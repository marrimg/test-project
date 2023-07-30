/*
  ==============================================================================

    amui_Card.h
    Created: 29 Jul 2023 10:16:07pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once
namespace amui {
class Card: public juce::Component {
public:
    Card(){}
    ~Card(){}
    void paint (juce::Graphics& g) override
    {
        g.setColour (juce::Colours::white);
 
        auto centralArea = getLocalBounds().toFloat().reduced (1.0f);
        g.drawRoundedRectangle (centralArea, 5.0f, 0.5f);

    }
};
};
