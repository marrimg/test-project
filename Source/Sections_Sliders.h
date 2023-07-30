/*
  ==============================================================================

    Sections_Sliders.h
    Created: 29 Jul 2023 11:08:54pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "GUI_Classes.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Sections_Header.h"

class Sliders: public juce::Component
{
    
public:
    Sliders(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        knob.setBounds(area);
        addAndMakeVisible(slider);
        addAndMakeVisible(textHeader);
        addAndMakeVisible(knob);
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

        
        grid.items = { gridItem(textHeader), gridItem(knob), gridItem(slider) };
        grid.templateRows = { Track (fr(1)), Track (fr(1)), Track (fr(1)) };
        grid.templateColumns = { fr(1)};
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), area.getHeight()));

    }
    
    ~Sliders(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    int gap = 2;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::Knob knob {Sliders::classMemberProcessor, "KnobDemoState", "Knob"};
    amui::TextHeader textHeader { "Sliders and knobs", amui::TextHeader::levels::SECONDARY };
    amui::Slider slider { Sliders::classMemberProcessor, "SliderDemoState", "Slider"};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sliders)
};



