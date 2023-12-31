/*
  ==============================================================================

    Params.h
    Created: 3 Dec 2022 10:25:05am
    Author:  jeph

  ==============================================================================
*/

#pragma once
#include "PluginProcessor.h"

// **************************************************
// This file sets up the APVTS parameter layout
// **************************************************

juce::AudioProcessorValueTreeState::ParameterLayout
AntimatterUITemplateAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
    // AMUI Component Demo State
    // Knob state
    auto KnobDemoState = std::make_unique<juce::AudioParameterInt> ("KnobDemoState", "KnobDemoState", 0, 100, 0);
    auto TextButtonDemoState = std::make_unique<juce::AudioParameterInt>("TextButtonDemoState", "TextButtonDemoState", 0, 1, 0);
    auto ComboBoxDemoState = std::make_unique<juce::AudioParameterInt>("ComboBoxDemoState", "ComboBoxDemoState", 1, 3, 1);
    auto SliderVerticalDemoState = std::make_unique<juce::AudioParameterInt>("SliderVerticalDemoState", "SliderVerticalDemoState", 0, 100, 0);
    auto SliderHorizontalDemoState = std::make_unique<juce::AudioParameterInt>("SliderHorizontalDemoState", "SliderHorizontalDemoState", 0, 100, 0);

//    auto scaleButtonToggleStateC = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.C, scaleButtonToggleState.C, 0, 1, 0);
  
    
    layout.add(
               std::move(KnobDemoState),
               std::move(TextButtonDemoState),
               std::move(ComboBoxDemoState),
               std::move(SliderHorizontalDemoState),
               std::move(SliderVerticalDemoState)
               );
    
    return layout;
}



