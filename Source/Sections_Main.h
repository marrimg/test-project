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
#include "PluginProcessor.h"
#include "Sections_Header.h"
#include "Sections_Inputs.h"
#include "Sections_Buttons.h"
#include "Sections_Sliders.h"
#include "Sections_Typography.h"
#include "Sections_Feedback.h"

/*
 This file is the main page layout for the module.
 It currently displays a demo layout of all the UI elements in the AMUI UI library.
 The elements that are displayed in the demo are split up into separate files by category. These files are imported above.
 You can reuse these category files to create sections for a real module layout, or create new files for each section and import them to this file.
 */

class Main: public juce::Component
{
    
public:
    Main(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p), header(p), inputs(p), buttons(p), sliders(p)
    {
        /* Adds and makes all of the components that we want to display in this section visible. */
        addAndMakeVisible(header);
        addAndMakeVisible(inputs);
        addAndMakeVisible(buttons);
        addAndMakeVisible(feedback);
        addAndMakeVisible(sliders);
        addAndMakeVisible(typography);
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

        fb.items.add(juce::FlexItem(header).withFlex (1));
        fb.items.add(juce::FlexItem(inputs).withFlex (1));
        fb.items.add(juce::FlexItem(feedback).withFlex (2));
        fb.items.add(juce::FlexItem(buttons).withFlex (1));
        fb.items.add(juce::FlexItem(sliders).withFlex (3));
        fb.items.add(juce::FlexItem(typography).withFlex (3));

        fb.performLayout (area);
    }
    
    ~Main(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    Header header;
    Inputs inputs;
    Buttons buttons;
    Sliders sliders;
    Typography typography;
    Feedback feedback;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Main)
};


