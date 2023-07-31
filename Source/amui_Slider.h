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
    enum directions {VERTICAL, HORIZONTAL};
    Slider(AntimatterUITemplateAudioProcessor& p, juce::String sliderAttachmentId, directions direction = VERTICAL, juce::String labelText = "")
    {
        if(direction == VERTICAL){
            slider.setSliderStyle(juce::Slider::LinearVertical);
        } else if (direction == HORIZONTAL) {
            slider.setSliderStyle(juce::Slider::LinearHorizontal);
        }
        label.setText(labelText, juce::dontSendNotification);
        slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);

        sliderAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.APVTS, sliderAttachmentId, slider));
    }
    
    void paint (juce::Graphics& g) override
    {}
    
    void resized() override
    {
        if(label.getText().length() > 0){
            addAndMakeVisible(label);
        }
        auto area = getLocalBounds();
        slider.setBounds(area);
        label.setBounds(area);
        label.setJustificationType (juce::Justification::centred);
        addAndMakeVisible(slider);
        addAndMakeVisible(label);
        
        juce::FlexBox fb;
        fb.flexDirection = juce::FlexBox::Direction::column;
        fb.justifyContent = juce::FlexBox::JustifyContent::center;
        fb.alignContent = juce::FlexBox::AlignContent::center;

        fb.items.add(juce::FlexItem(slider).withFlex (4));
        fb.items.add(juce::FlexItem(label).withFlex (1));

        fb.performLayout (getLocalBounds());
    }
    
    ~Slider(){
        sliderAttachment.reset();
    }
    
private:
    juce::Slider slider;
    juce::Label label;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Slider)
};
};

