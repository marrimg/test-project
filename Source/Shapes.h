/*
  ==============================================================================

    Shapes.h
    Created: 2 Jan 2023 4:28:01pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

static const juce::Path getRightArrow(int width, int height){
    juce::Path Triangle;
    Triangle.addTriangle(0, 0, width, height/2, 0, height);
    return Triangle;
}

static const juce::Path getLeftArrow(int width, int height){
    juce::Path Triangle;
    Triangle.addTriangle(0, height/2, width, 0,width, height);
    return Triangle;
}
