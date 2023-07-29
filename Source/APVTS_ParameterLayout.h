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
    // ImageKnob state
    auto ImageKnobDemoState = std::make_unique<juce::AudioParameterInt> ("ImageKnobDemoState", "ImageKnobDemoState", 0, 100, 0);
    auto TextButtonDemoState = std::make_unique<juce::AudioParameterInt>("TextButtonDemoState", "TextButtonDemoState", 0, 1, 0);
//    auto scaleButtonToggleStateC = std::make_unique<juce::AudioParameterInt> (scaleButtonToggleState.C, scaleButtonToggleState.C, 0, 1, 0);
  
    
    layout.add(
               std::move(ImageKnobDemoState),
               std::move(TextButtonDemoState)
               );
    
    return layout;
}



