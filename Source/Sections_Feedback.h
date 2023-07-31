/*
  ==============================================================================

    Sections_Feedback.h
    Created: 30 Jul 2023 2:01:27pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
#include "amui.h"

/* UI elements that give visual feedback to the user */

class Feedback: public juce::Component
{
    
public:
    Feedback()
    {
        /* Adds and makes all of the components that we want to display in this section visible. */
        addAndMakeVisible(textHeader);
        addAndMakeVisible(ledHeader);
        addAndMakeVisible(ledOn);
        addAndMakeVisible(ledOff);
    }
    
    void resized() override
    {
        /* Sets the state of the LED to ON */
        ledOn.setState(amui::LED::states::ON);
        
        /* Creates a rectangle for the area of the component that has padding subtracted from it. This will create padding around the component. */
        auto area = getLocalBounds();
        area.removeFromRight(padding);
        area.removeFromLeft(padding);
        area.removeFromBottom(padding);
        area.removeFromTop(padding);

        /* Creates a FlexBox layout and adds the components to the layout. Performs the layout within the area that we set up above. */
        juce::FlexBox fb;
        fb.flexWrap = juce::FlexBox::Wrap::wrap;
        juce::FlexItem title  ((float) getWidth(), (float) getHeight()/4.0f, textHeader);
        juce::FlexItem sectionHeader  ((float) getWidth(), (float) getHeight()/4.0f, ledHeader);
        juce::FlexItem ledOnSection ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOn);
        juce::FlexItem ledOffSection  ((float) getWidth() / 3.3f, (float) getHeight()/4.0f, ledOff);
        fb.items.addArray ( { title, sectionHeader, ledOnSection, ledOffSection } );
        fb.performLayout (area);
    }
    
    ~Feedback(){
        setLookAndFeel(nullptr);
    }
    
private:
    int padding = 10;
    amui::TextHeader textHeader {"Visual feedback", amui::TextHeader::levels::SECONDARY};
    amui::TextHeader ledHeader {"LEDs on/off", amui::TextHeader::levels::SECONDARY};
    amui::LED ledOn;
    amui::LED ledOff;
    juce::Label label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Feedback)
};




