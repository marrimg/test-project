/*
  ==============================================================================

    Sections_Inputs.h
    Created: 29 Jul 2023 11:09:19pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "PluginProcessor.h"

/* UI input elements */

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
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;

        fb.items.add(juce::FlexItem(textHeader).withFlex (1));
        fb.items.add(juce::FlexItem(comboBox).withFlex (1));

        fb.performLayout (area);
        

    }
    
    ~Inputs(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::TextHeader textHeader { "Inputs", amui::TextHeader::levels::SECONDARY };
    amui::ComboBox comboBox { Inputs::classMemberProcessor, "ComboBoxDemoState", {"combobox option 1", "combobox option 2", "combobox option 3"} };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Inputs)
};



