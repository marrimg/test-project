/*
  ==============================================================================

    Sections_Typography.h
    Created: 29 Jul 2023 11:09:30pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"

/* Typography elements */

class Typography: public juce::Component
{
    
public:
    Typography()
    {

        auto area = getLocalBounds();
    
        sectionHeader.setBounds(area);
        primaryTextHeader.setBounds(area);
        secondaryTextHeader.setBounds(area);
        textBlock.setBounds(area);
        addAndMakeVisible(sectionHeader);
        addAndMakeVisible(primaryTextHeader);
        addAndMakeVisible(secondaryTextHeader);
        addAndMakeVisible(textBlock);
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

        fb.items.add(juce::FlexItem(sectionHeader).withFlex (1));
        fb.items.add(juce::FlexItem(primaryTextHeader).withFlex (1));
        fb.items.add(juce::FlexItem(secondaryTextHeader).withFlex (1));
        fb.items.add(juce::FlexItem(textBlock).withFlex (1));
        fb.performLayout (area);
    }
    
    ~Typography(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    amui::TextHeader sectionHeader { "Typography", amui::TextHeader::levels::SECONDARY };
    amui::TextHeader primaryTextHeader { "Primary TextHeader" };
    amui::TextHeader secondaryTextHeader { "Secondary TextHeader", amui::TextHeader::levels::SECONDARY };
    amui::TextBlock textBlock {"This is a text block. It displays a block of text."};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Typography)
};



