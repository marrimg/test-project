

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Sections_Main.h"

//==============================================================================
AntimatterUITemplateAudioProcessorEditor::AntimatterUITemplateAudioProcessorEditor (AntimatterUITemplateAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), mainComponent(p)
{
    mainComponent.setBounds (0, 0, getWidth(), getHeight());
    addAndMakeVisible(mainComponent);
    
    setSize (800, 600);
}

AntimatterUITemplateAudioProcessorEditor::~AntimatterUITemplateAudioProcessorEditor()
{
}

//==============================================================================
void AntimatterUITemplateAudioProcessorEditor::paint (juce::Graphics& g)
{
 
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void AntimatterUITemplateAudioProcessorEditor::resized()
{
    mainComponent.setBounds (0, 0, getWidth(), getHeight());
}
