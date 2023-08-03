/*
  ==============================================================================

    amui_TextBlock.h
    Created: 30 Jul 2023 1:30:08pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class TextBlock: public juce::Component {
public:
    TextBlock(juce::String text){
        textBlock.setText(text, juce::dontSendNotification);
    }
    void resized() override{
        auto area = getLocalBounds();
        textBlock.setBounds(area);
        addAndMakeVisible(textBlock);
    }
    ~TextBlock(){}
private:
    juce::Label textBlock;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextBlock)
};
};
