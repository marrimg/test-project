
#pragma once
#include <JuceHeader.h>

namespace amui {
//This works for framed knobs or sliders
class Knob : public juce::Slider
{
public:
    Knob(juce::Image image, juce::String attachmentId, AntimatterUITemplateAudioProcessor& p, const int numFrames = 50, const bool stripIsHorizontal = false, int index = 0)
    :  Slider(juce::String(index)),
    filmStrip(image),
    numFrames_(numFrames),
    isHorizontal_(stripIsHorizontal)

    {
        Slider.setBounds(0, 0, 10, 10);
        if(filmStrip.isValid())
        {
            KnobAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (p.APVTS, attachmentId, Slider));

            setTextBoxStyle(NoTextBox, 0, 0, 0);
            setSliderStyle(RotaryVerticalDrag);
            frameHeight = filmStrip.getHeight() / numFrames_;
            frameWidth = filmStrip.getWidth();
            setRange(0.0f, 1.0f, 0.001f);
        }
    }
    
    void paint(juce::Graphics& g) override
    {
        if(filmStrip.isValid()) {
            int value = (int)((getValue() - getMinimum()) / (getMaximum() - getMinimum()) * (numFrames_ - 1));
            if(isHorizontal_) {
                g.drawImage(filmStrip, 0, 0, getWidth(), getHeight(),
                            value * frameWidth, 0, frameWidth, frameHeight);
            } else {
                g.drawImage(filmStrip, 0, 0, getWidth(), getHeight(),
                            0, value * frameHeight, frameWidth, frameHeight);
            }
        }
    }
    
    void resized() override {
        Slider.setBounds(0, 0, 10, 10);
    }

    ~Knob(){
        KnobAttachment.reset();
    }
    
private:
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> KnobAttachment;
    juce::Slider Slider;
    juce::Image filmStrip;
    const int numFrames_;
    const bool isHorizontal_;
    int frameWidth, frameHeight;
};
} // namespace

