/*
  ==============================================================================

    Sections_Sliders.h
    Created: 29 Jul 2023 11:08:54pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"
#include "PluginProcessor.h"

/* Knobs and sliders */

class Sliders: public juce::Component
{
    
public:
    Sliders(AntimatterUITemplateAudioProcessor& p): classMemberProcessor(p)
    {
        addAndMakeVisible(textHeader);
        addAndMakeVisible(sliderVertical);
        addAndMakeVisible(sliderHorizontal);
        addAndMakeVisible(knob);
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
        
        juce::FlexBox fb;
        fb.flexWrap = juce::FlexBox::Wrap::wrap;
        juce::FlexItem top  ((float) getWidth(), (float) getHeight()/2.0f, textHeader);
        juce::FlexItem knobSection ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, knob);
        juce::FlexItem sliderVerticalSection  ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, sliderVertical);
        juce::FlexItem sliderHorizontalSection  ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, sliderHorizontal);
        fb.items.addArray ( { top, knobSection, sliderVerticalSection, sliderHorizontalSection } );
        fb.performLayout (area);
    }
    
    ~Sliders(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    AntimatterUITemplateAudioProcessor& classMemberProcessor;
    amui::Knob knob {Sliders::classMemberProcessor, "KnobDemoState", "Knob"};
    amui::TextHeader textHeader { "Sliders and knobs", amui::TextHeader::levels::SECONDARY };
    amui::Slider sliderVertical { Sliders::classMemberProcessor, "SliderVerticalDemoState", amui::Slider::directions::VERTICAL, "Vertical Slider"};
    amui::Slider sliderHorizontal { Sliders::classMemberProcessor, "SliderHorizontalDemoState", amui::Slider::directions::HORIZONTAL, "Horizontal Slider"};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sliders)
};



