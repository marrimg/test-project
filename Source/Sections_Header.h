/*
  ==============================================================================

    PageHeader.h
    Created: 19 Jun 2023 2:48:09pm
    Author:  Marri Gamard

  ==============================================================================
*/


#pragma once
#include "amui.h"

class Header: public amui::Card
{
    
public:
    Header(AntimatterUITemplateAudioProcessor& p)
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        addAndMakeVisible(textHeader);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        addAndMakeVisible(textHeader);
//        juce::Grid grid;
//
//        using Track = juce::Grid::TrackInfo;
//        using fr = juce::Grid::Fr;
//        using px = juce::Grid::Px;
//        using gridItem = juce::GridItem;
//
//        auto area = getLocalBounds();
//        area.removeFromRight(padding);
//        area.removeFromLeft(padding);
//        area.removeFromBottom(padding);
//        area.removeFromTop(padding);
//
//
//        grid.items = { gridItem(textHeader) };
//        grid.templateRows = { Track (fr(1)) };
//        grid.templateColumns = { fr(1)};
//        grid.setGap(px(gap));
//        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), 300));

    }
    
    ~Header(){
        setLookAndFeel(nullptr);
    }
    
private:
    amui::TextHeader textHeader { "TextHeader2" };
    int padding = 4;
    int gap = 4;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};



