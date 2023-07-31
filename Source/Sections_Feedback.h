/*
  ==============================================================================

    Sections_Feedback.h
    Created: 30 Jul 2023 2:01:27pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"

class Feedback: public juce::Component
{
    
public:
    Feedback()
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        ledOn.setBounds(area);
        ledOff.setBounds(area);
        addAndMakeVisible(textHeader);
        addAndMakeVisible(ledOn);
        addAndMakeVisible(ledOff);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        ledOn.setBounds(area);
        ledOff.setBounds(area);
        ledOn.setState(amui::LED::states::ON);
        
        addAndMakeVisible(textHeader);
        addAndMakeVisible(ledOn);
        addAndMakeVisible(ledOff);
        
        juce::Grid grid;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        using gridItem = juce::GridItem;
        

        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        juce::FlexBox fb;
        fb.flexWrap = juce::FlexBox::Wrap::wrap;
        juce::FlexItem top  ((float) getWidth(), (float) getHeight()/2.0f, textHeader);
        juce::FlexItem ledOnSection ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOn);
        juce::FlexItem ledOffSection  ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOff);
        fb.items.addArray ( { top, ledOnSection, ledOffSection } );
        fb.performLayout (getLocalBounds());
    }
    
    ~Feedback(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    amui::TextHeader textHeader {"Visual feedback", amui::TextHeader::levels::SECONDARY};
    amui::LED ledOn;
    amui::LED ledOff;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Feedback)
};




