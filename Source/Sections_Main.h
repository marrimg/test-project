/*
  ==============================================================================

    Main.h
    Created: 19 Jun 2023 2:46:58pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Sections_Header.h"
#include "Sections_Inputs.h"
#include "Sections_Buttons.h"
#include "Sections_Sliders.h"
#include "Sections_Typography.h"

class Main: public juce::Component
{
    
public:
    Main(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p), header(p), inputs(p), buttons(p), sliders(p)
    {

        auto area = getLocalBounds();
    
        addAndMakeVisible(header);
        addAndMakeVisible(inputs);
        addAndMakeVisible(buttons);
        addAndMakeVisible(sliders);
        addAndMakeVisible(typography);
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
        
        grid.items = {gridItem(header), gridItem(inputs),  gridItem(buttons), gridItem(sliders), gridItem(typography) };
        grid.templateRows = { Track (fr(1)), Track (fr(2)), Track (fr(2)), Track (fr(4)), Track (fr(2)) };
        grid.templateColumns = { fr(1)};
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), area.getHeight()));
    }
    
    ~Main(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    int gap = 2;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    Header header;
    Inputs inputs;
    Buttons buttons;
    Sliders sliders;
    Typography typography;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Main)
};


