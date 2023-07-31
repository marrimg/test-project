/*
  ==============================================================================

    PageHeader.h
    Created: 19 Jun 2023 2:48:09pm
    Author:  Marri Gamard

  ==============================================================================
*/


#pragma once
#include "amui.h"

/* Main page header */

class Header: public juce::Component
{
    
public:
    Header(AntimatterUITemplateAudioProcessor& p)
    {
        addAndMakeVisible(textHeader);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);
        addAndMakeVisible(textHeader);

    }
    
    ~Header(){
        setLookAndFeel(nullptr);
    }
    
private:
    amui::TextHeader textHeader { "Antimatter UI Template" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};



