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

    Knob(AntimatterUITemplateAudioProcessor& p, juce::String knobAttachmentId, juce::String labelText = "")
    {
        label.setText(labelText, juce::dontSendNotification);
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
        if(label.getText().length() > 0){
            addAndMakeVisible(label);
        }
        auto area = getLocalBounds();
        knob.setBounds(area);
        label.setBounds(area);
        label.setJustificationType (juce::Justification::centred);
        addAndMakeVisible(knob);
        addAndMakeVisible(label);
        
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;
        fb.justifyContent = juce::FlexBox::JustifyContent::center;
        fb.alignContent = juce::FlexBox::AlignContent::center;

        fb.items.add(juce::FlexItem(knob).withFlex (4));
        fb.items.add(juce::FlexItem(label).withFlex (1));

        fb.performLayout (getLocalBounds());
    }
    
    ~Knob(){
        knobAttachment.reset();
    }
    
private:
    juce::Slider knob;
    juce::Label label;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> knobAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob)
};
};

