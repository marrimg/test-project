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
        /* Adds and makes all of the components that we want to display in this section visible. */
        addAndMakeVisible(textHeader);
        addAndMakeVisible(comboBox);
    }
    
    void paint (juce::Graphics& g) override
    {

    }
    
    void resized() override
    {
        /* Creates a rectangle for the area of the component that has padding subtracted from it. This will create padding around the component. */
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);
        
        /* Creates a FlexBox layout and adds the components to the layout. Performs the layout within the area that we set up above. */
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



