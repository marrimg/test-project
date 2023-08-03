/*
  ==============================================================================

    PageHeader.h
    Created: 19 Jun 2023 2:48:09pm
    Author:  Marri Gamard

  ==============================================================================
*/


#pragma once
#include "amui/amui.h"

/* Main page header. Currently displays a text header only. */

class Header: public juce::Component
{
    
public:
    Header(AntimatterUITemplateAudioProcessor& p)
    {
        /* Adds and makes all of the components that we want to display in this section visible. */
        addAndMakeVisible(textHeader);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        textHeader.setBounds(area);

    }
    
    ~Header(){
        setLookAndFeel(nullptr);
    }
    
private:
    amui::TextHeader textHeader { "Antimatter UI Template" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};



