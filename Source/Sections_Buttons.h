/*
  ==============================================================================

    Sections_Buttons.h
    Created: 29 Jul 2023 11:09:07pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"

class Buttons: public amui::Card
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

        
        grid.items = { gridItem(textHeader), gridItem(textButton) };
        grid.templateRows = { Track (fr(1)), Track (fr(1)) };
        grid.templateColumns = { fr(1)};
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), area.getHeight()));
    }
    
    ~Buttons(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    int gap = 2;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::TextButton textButton { Buttons::classMemberProcessor, "TextButtonDemoState", "TextButton" };
    amui::TextHeader textHeader { "Buttons", amui::TextHeader::levels::SECONDARY };
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Buttons)
};



