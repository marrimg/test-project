/*
  ==============================================================================

    Sections_Feedback.h
    Created: 30 Jul 2023 2:01:27pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"

/* Ui elements that give visual feedback to the user */

class Feedback: public juce::Component
{
    
public:
    Feedback()
    {
        addAndMakeVisible(textHeader);
        addAndMakeVisible(ledOn);
        addAndMakeVisible(ledOff);
    }
    
    void resized() override
    {
        /* Creates a rectangle for the area of the component that has padding subtracted from it. This will create padding around the component. */
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        textHeader.setBounds(area);
        ledHeader.setBounds(area);
        ledOn.setBounds(area);
        ledOff.setBounds(area);
        ledOn.setState(amui::LED::states::ON);
        
        addAndMakeVisible(textHeader);
        addAndMakeVisible(ledHeader);
        addAndMakeVisible(ledOn);
        addAndMakeVisible(ledOff);
        
        juce::FlexBox fb;
        fb.flexWrap = juce::FlexBox::Wrap::wrap;
        juce::FlexItem title  ((float) getWidth(), (float) getHeight()/4.0f, textHeader);
        juce::FlexItem sectionHeader  ((float) getWidth(), (float) getHeight()/4.0f, ledHeader);
        juce::FlexItem ledOnSection ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOn);
        juce::FlexItem ledOffSection  ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOff);
        fb.items.addArray ( { title, sectionHeader, ledOnSection, ledOffSection } );
        fb.performLayout (area);
    }
    
    ~Feedback(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    amui::TextHeader textHeader {"Visual feedback", amui::TextHeader::levels::SECONDARY};
    amui::TextHeader ledHeader {"LEDs on/off", amui::TextHeader::levels::SECONDARY};
    amui::LED ledOn;
    amui::LED ledOff;
    juce::Label label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Feedback)
};




