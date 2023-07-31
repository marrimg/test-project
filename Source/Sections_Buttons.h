/*
  ==============================================================================

    Sections_Buttons.h
    Created: 29 Jul 2023 11:09:07pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "PluginProcessor.h"

class Buttons: public juce::Component
{
    
public:
    Buttons(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {

        auto area = getLocalBounds();
        textHeader.setBounds(area);
        textButton.setBounds (area);
        addAndMakeVisible(textHeader);
        addAndMakeVisible(textButton);
    }
    
    void paint (juce::Graphics& g) override
    {

    }
    
    void resized() override
    {
        
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;

        fb.items.add(juce::FlexItem(textHeader).withFlex (1));
        fb.items.add(juce::FlexItem(textButton).withFlex (1));

        fb.performLayout (area);
    }
    
    ~Buttons(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::TextButton textButton { Buttons::classMemberProcessor, "TextButtonDemoState", "TextButton" };
    amui::TextHeader textHeader { "Buttons", amui::TextHeader::levels::SECONDARY };
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Buttons)
};



