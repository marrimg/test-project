/*
  ==============================================================================

    Sections_Typography.h
    Created: 29 Jul 2023 11:09:30pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Sections_Header.h"

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
        juce::Grid grid;
        
        using Track = juce::Grid::TrackInfo;
        using fr = juce::Grid::Fr;
        using px = juce::Grid::Px;
        using gridItem = juce::GridItem;
        
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        grid.items = {gridItem(sectionHeader), gridItem(primaryTextHeader), gridItem(secondaryTextHeader), gridItem(textBlock) };
        grid.templateRows = { Track (fr(1)), Track (fr(1)), Track (fr(1)), Track (fr(1)) };
        grid.templateColumns = { fr(1) };
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), area.getHeight()));
    }
    
    ~Typography(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    int gap = 2;
    amui::TextHeader sectionHeader { "Typography", amui::TextHeader::levels::SECONDARY };
    amui::TextHeader primaryTextHeader { "Primary TextHeader" };
    amui::TextHeader secondaryTextHeader { "Secondary TextHeader", amui::TextHeader::levels::SECONDARY };
    amui::TextBlock textBlock {"This is a text block. It displays a block of text."};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Typography)
};



