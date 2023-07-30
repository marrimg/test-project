/*
  ==============================================================================

    Sections_Inputs.h
    Created: 29 Jul 2023 11:09:19pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Sections_Header.h"

class Inputs: public juce::Component
{
    
public:
    Inputs(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        comboBox.setBounds(area);
        addAndMakeVisible(textHeader);
        addAndMakeVisible(comboBox);
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
        
        grid.items = { gridItem(textHeader), gridItem(comboBox) };
        grid.templateRows = { Track (fr(1)), Track (fr(1)) };
        grid.templateColumns = { fr(1)};
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), area.getHeight()));

    }
    
    ~Inputs(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    int gap = 2;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::TextHeader textHeader { "Inputs", amui::TextHeader::levels::SECONDARY };
    amui::ComboBox comboBox { Inputs::classMemberProcessor, "ComboBoxDemoState", {"combobox option 1", "combobox option 2", "combobox option 3"} };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Inputs)
};



