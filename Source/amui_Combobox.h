/*
  ==============================================================================

    Combobox.h
    Created: 19 Jun 2023 2:25:13pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class ComboBox: public juce::Component {
public:
    ComboBox(AntimatterUITemplateAudioProcessor& p, juce::String ComboBoxAttachmentId, std::vector<juce::String> items){
//        addAndMakeVisible(comboBox);
        for(auto i=0; i<items.size(); i++){
            comboBox.addItem(items.at(i), i+1);
        }
        comboBox.onChange = [this] { comboBoxChanged(); };
        comboBox.setSelectedId (1);
        comboBoxAttachment.reset(new juce::AudioProcessorValueTreeState::ComboBoxAttachment (p.APVTS, ComboBoxAttachmentId, comboBox));

    }
    void comboBoxChanged()
    {
        switch (comboBox.getSelectedId())
        {
            case 1: textFont.setStyleFlags (juce::Font::plain);  break;
            case 2: textFont.setStyleFlags (juce::Font::bold);   break;
            case 3: textFont.setStyleFlags (juce::Font::italic); break;
            default: break;
        }
 
    }
    
    void resized() override{
        auto area = getLocalBounds();
        comboBox.setBounds (area);
        addAndMakeVisible(comboBox);
    }
    ~ComboBox(){}
private:
    juce::ComboBox comboBox;
    juce::Font textFont   { 12.0f };
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> comboBoxAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBox)
};
};
