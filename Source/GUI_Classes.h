/*
 ==============================================================================
 
 LookAndFeel.h
 Created: 16 Nov 2022 12:42:06pm
 Author:  Marri Gamard
 
 ==============================================================================
 */

#pragma once
#include "PluginEditor.h"
#include "StyleConstants.h"

//Embed font
static const juce::Font getCustomFont()
{
    static auto typeface = juce::Typeface::createSystemTypefaceFor (BinaryData::HelveticaNeue_ttc, BinaryData::HelveticaNeue_ttcSize);
    return juce::Font (typeface);
}


class RoundedRectangleBackground : public juce::LookAndFeel_V4 {
    public:
    void drawBackground (juce::Graphics& g, juce::Rectangle<int> area, juce::Colour color = midGrey, int borderHorizontal = 4,  int borderVertical = 4){
        const float x = borderHorizontal;
        const float y = borderVertical;
        area.removeFromLeft (borderHorizontal);
        area.removeFromTop (borderVertical);
        area.removeFromRight (borderHorizontal);
        area.removeFromBottom (borderVertical);
        auto w = area.getWidth();
        auto h = area.getHeight();
        g.setColour (color);
        g.fillRoundedRectangle(x, y, w, h, radius);
    }
    const float radius = 15.0f;
};

class ScaleButtonLookAndFeel : public juce::LookAndFeel_V4
{
public:
    int borderThick = 4;
    int borderThin = 2;
    
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        //Main area and border
        auto buttonArea = button.getLocalBounds();
        
        buttonArea.removeFromLeft (borderThick);
        buttonArea.removeFromTop (borderThick);
        buttonArea.removeFromRight (borderThick);
        buttonArea.removeFromBottom (borderThick);
        button.setClickingTogglesState(1);
        
        g.setColour (darkGrey1);
        g.drawRoundedRectangle(borderThick, borderThick, buttonArea.getWidth(), buttonArea.getHeight(),12, borderThick);
        g.setColour (lightGrey);
        g.fillRoundedRectangle (borderThick + 2, borderThick + 2, buttonArea.getWidth() - borderThick, buttonArea.getHeight() - borderThick, 9);
        
        //Make LED
        
        float leftIndent = 12;
        float rightIndent = 12;
        float ledWidth = button.getWidth() - leftIndent - rightIndent;
        float ledHeight = buttonArea.getHeight() * .2;
        
        juce::Path ledRect;
        
        ledRect.addRoundedRectangle(leftIndent, button.getHeight() * .6, ledWidth, ledHeight, 2);
        
        float ledCenterX = ledRect.getBounds().getCentreX();
        float ledCenterY = ledRect.getBounds().getCentreY();
        
        if(button.getToggleState() == 0)
        {
            juce::ColourGradient ledGradient = juce::ColourGradient(whiteGrey, ledCenterX, ledCenterY, lightGrey, ledRect.getBounds().getX() + 3,  ledRect.getBounds().getY() + 3, true);
            g.setFillType(ledGradient);
        }
        
        if(button.getToggleState() == 1)
        {
            juce::ColourGradient ledGradient = juce::ColourGradient(lightOrange, ledCenterX, ledCenterY, orange, ledRect.getBounds().getX() +3,  ledRect.getBounds().getY() +3, true);
            g.setFillType(ledGradient);
        }
        
        g.fillPath(ledRect);
        
        g.setColour (darkGrey1);
        g.strokePath (ledRect, juce::PathStrokeType (2.0f));
    }
    
    
    void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown) override
    {
        auto font = getTextButtonFont (button, button.getHeight());
        g.setFont (font);
        g.setColour (white);
        
        //Label text
        
        g.setFont(getCustomFont());
        g.setFont(20);
        
        auto yIndent = button.proportionOfHeight (0.25);
        auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;
        
        auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
        auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
        auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        auto textWidth = button.getWidth() - leftIndent - rightIndent;
        
        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent, yIndent, textWidth, button.getHeight() - yIndent,
                              juce::Justification::centredTop, 2);
    }
    
};



// TODO: Consolidate left and right button classes
class RightArrowButtonLookAndFeel : public juce::LookAndFeel_V4
{
public:

    void drawButtonBackground (juce::Graphics& g, juce::Button& ArrowButton, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        juce::Path Triangle;
        juce::AffineTransform transform;
        
        ArrowButton.setBoundsRelative(0, 0, 1.0, 1.0);
        Triangle.addTriangle(0, ArrowButton.getHeight()/2, ArrowButton.getWidth(), 0,ArrowButton.getWidth(), ArrowButton.getHeight());
        
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
    
        transform = transform.rotation(3.14, ArrowButton.getWidth()/2, ArrowButton.getHeight()/2);
        g.fillPath(Triangle, transform);
    }
};

// TODO: Consolidate left and right button classes
class LeftArrowButtonLookAndFeel : public juce::LookAndFeel_V4
{
public:

    void drawButtonBackground (juce::Graphics& g, juce::Button& ArrowButton, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        juce::Path Triangle;
        
        ArrowButton.setBoundsRelative(0, 0, 1.0, 1.0);
        Triangle.addTriangle(0, ArrowButton.getHeight()/2, ArrowButton.getWidth(), 0,ArrowButton.getWidth(), ArrowButton.getHeight());
        
        auto fillType = juce::FillType();
        fillType.setColour(darkGrey1);
        g.setFillType(fillType);
    
        g.fillPath(Triangle);
    }
};
    
// TODO: Fix secector button styles
////The triangular button used for octave shifts
//class OctaveButton : public juce::LookAndFeel_V4
//{
//public:
//    int borderThick = 4;
//    int borderThin = 2;
//    
//    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
//                               bool, bool isButtonDown) override
//    {
//        //Main area and border
//        auto buttonArea = button.getLocalBounds();
//        
//        buttonArea.removeFromLeft (borderThick);
//        buttonArea.removeFromTop (borderThick);
//        buttonArea.removeFromRight (borderThick);
//        buttonArea.removeFromBottom (borderThick);
//        button.setClickingTogglesState(1);
//        
//        juce::Path octTriangle;
//        
//        octTriangle.addTriangle(button.getWidth(), button.getHeight(), button.getWidth(), button.getHeight(), button.getWidth(), button.getHeight());
//
//        g.fillPath(octTriangle);
//        
//        g.setColour (darkGrey1);
//        g.strokePath (octTriangle, juce::PathStrokeType (2.0f));
//    }
//};

