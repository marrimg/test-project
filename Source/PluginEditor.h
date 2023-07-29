
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Sections_Main.h"

//==============================================================================

class AntimatterUITemplateAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AntimatterUITemplateAudioProcessorEditor (AntimatterUITemplateAudioProcessor&);
    ~AntimatterUITemplateAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    
    
private:

    AntimatterUITemplateAudioProcessor& audioProcessor;

    Main mainComponent;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AntimatterUITemplateAudioProcessorEditor)
};
