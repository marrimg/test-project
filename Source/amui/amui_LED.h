/*
  ==============================================================================

    amui_LED.h
    Created: 30 Jul 2023 1:30:45pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class LED: public juce::Component {
public:
    enum states {ON, OFF};
    states state = OFF;
    LED(){}
    void setState(states newState) {
        if (newState == ON){
            state = ON;
        } else if (newState == OFF){
            state = OFF;
        }
    }
    void resized() override{
    }
    void paint(juce::Graphics& g) override{
        if(state == ON){
            g.setColour(juce::Colours::red);
            g.fillRect(led);
        } else if(state == OFF){
            g.setColour(juce::Colours::grey);
            g.fillRect(led);
        }
        g.setColour(juce::Colours::white);
        g.drawRect(led);
    }
    ~LED(){}
private:
    float ledSize =  12.0f;
    juce::Rectangle<float> led {0.0f, 0.0f, ledSize, ledSize};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LED)
};
};

