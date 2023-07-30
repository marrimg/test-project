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

class Main: public juce::Component
{
    
public:
    Main(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {

        auto area = getLocalBounds();
    
//        imageKnob.setBounds (area);
//        addAndMakeVisible(imageKnob);
        textHeader.setBounds(area);
        textButton.setBounds (area);
        comboBox.setBounds(area);
        addAndMakeVisible(comboBox);
        addAndMakeVisible(textButton);
        addAndMakeVisible(textHeader);

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
        
        grid.items = { gridItem(textButton), gridItem(textHeader), gridItem(comboBox) };
        grid.templateRows = { Track (fr(1)), Track (fr(1)), Track (fr(1)) };
        grid.templateColumns = { fr(1) };
        grid.setGap(px(gap));
        grid.performLayout(juce::Rectangle<int> (area.getX(), area.getY(), area.getWidth(), 75));
    }
    
    ~Main(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 20;
    int gap = 2;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::ImageKnob imageKnob {juce::ImageCache::getFromMemory(BinaryData::knob1_png, BinaryData::knob1_pngSize), "ImageKnobDemoState", classMemberProcessor};
    amui::TextButton textButton { Main::classMemberProcessor, "TextButtonDemoState", "TextButton" };
    amui::TextHeader textHeader { "TextHeader" };
    amui::ComboBox comboBox { Main::classMemberProcessor, "ComboBoxDemoState", {"combobox option 1", "combobox option 2"} };
//    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Main)
};


