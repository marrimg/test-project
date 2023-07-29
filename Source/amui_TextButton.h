/*
  ==============================================================================

    TextButton.h
    Created: 19 Jun 2023 2:25:55pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class TextButton: public juce::Component
{
    
public:

    TextButton(AntimatterUITemplateAudioProcessor& p, juce::String ButtonAttachmentId, juce::String label)
    {
        button.setClickingTogglesState(1);
        button.setButtonText(label);
        addAndMakeVisible(button);
        buttonAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment (p.APVTS, ButtonAttachmentId, button));
        auto area = getLocalBounds();
        button.setBounds(area);
        addAndMakeVisible(button);
    }
    
    void paint (juce::Graphics& g) override
    {
//        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        button.setBounds(area);
        addAndMakeVisible(button);
    }
    
    ~TextButton(){
        setLookAndFeel(nullptr);
        buttonAttachment.reset();
    }
    
private:
    juce::TextButton button;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> buttonAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextButton)
};
};
