/*
  ==============================================================================

    Knob.h
    Created: 19 Jun 2023 2:25:30pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class Knob: public juce::Component
{
    
public:

    Knob(AntimatterUITemplateAudioProcessor& p, juce::String knobAttachmentId, juce::String label)
    {
        knob.setSliderStyle (juce::Slider::SliderStyle::Rotary);
        knob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        knobAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.APVTS, knobAttachmentId, knob));
    }
    
    void paint (juce::Graphics& g) override
    {
//        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        knob.setBounds(area);
        addAndMakeVisible(knob);
    }
    
    ~Knob(){
        knobAttachment.reset();
    }
    
private:
    juce::Slider knob;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> knobAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob)
};
};

