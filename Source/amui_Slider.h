/*
  ==============================================================================

    Slider.h
    Created: 19 Jun 2023 2:25:30pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class Slider: public juce::Component
{
    
public:

    Slider(AntimatterUITemplateAudioProcessor& p, juce::String sliderAttachmentId, juce::String label)
    {
        slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
        sliderAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.APVTS, sliderAttachmentId, slider));
    }
    
    void paint (juce::Graphics& g) override
    {
//        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        slider.setBounds(area);
        addAndMakeVisible(slider);
    }
    
    ~Slider(){
        sliderAttachment.reset();
    }
    
private:
    juce::Slider slider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Slider)
};
};

