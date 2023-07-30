/*
  ==============================================================================

    TextHeader.h
    Created: 19 Jun 2023 2:25:13pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class TextHeader: public juce::Component {
public:
    TextHeader(juce::String text){
        label.setFont (juce::Font (16.0f, juce::Font::bold));
        label.setText (text, juce::dontSendNotification);
        addAndMakeVisible(label);
    }
    void resized() override{
        auto area = getLocalBounds();
        label.setBounds (area);
        addAndMakeVisible(label);
    }
    ~TextHeader(){}
private:
    juce::Label label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextHeader)
};
};
