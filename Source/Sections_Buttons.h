/*
  ==============================================================================

    Sections_Buttons.h
    Created: 29 Jul 2023 11:09:07pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui/amui.h"
#include "PluginProcessor.h"

/* Buttons */

class Buttons: public juce::Component
{
    
public:
    Buttons(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {
        /* Adds and makes all of the components that we want to display in this section visible. */
        addAndMakeVisible(textHeader);
        addAndMakeVisible(textButton);
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
        fb.items.add(juce::FlexItem(textButton).withFlex (1));

        fb.performLayout (area);
    }
    
    ~Buttons(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::TextButton textButton { Buttons::classMemberProcessor, "TextButtonDemoState", "TextButton" };
    amui::TextHeader textHeader { "Buttons", amui::TextHeader::levels::SECONDARY };
    RoundedRectangleBackground RoundedRectangleBackground;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Buttons)
};



