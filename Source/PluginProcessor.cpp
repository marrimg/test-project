/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "APVTS_ParameterLayout.h"

//==============================================================================
AntimatterUITemplateAudioProcessor::AntimatterUITemplateAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AntimatterUITemplateAudioProcessor::~AntimatterUITemplateAudioProcessor()
{
}

//==============================================================================
const juce::String AntimatterUITemplateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AntimatterUITemplateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AntimatterUITemplateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AntimatterUITemplateAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AntimatterUITemplateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AntimatterUITemplateAudioProcessor::getNumPrograms()
{
    return 1;
}

int AntimatterUITemplateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AntimatterUITemplateAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String AntimatterUITemplateAudioProcessor::getProgramName (int index)
{
    return {};
}

void AntimatterUITemplateAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//void AntimatterUITemplateAudioProcessor::getGuiParams()
//{
//    gui_var1 = APVTS.getRawParameterValue(scaleButtonOctaveState.C);
//    var1 = *gui_var1;
//    std::cout << var1 << "\r";
//}

//==============================================================================
void AntimatterUITemplateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void AntimatterUITemplateAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AntimatterUITemplateAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AntimatterUITemplateAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    auto ImageKnobDemoState = APVTS.getRawParameterValue("TextButtonDemoState");
    
    
//    getGuiParams();
    

    
    std::cout << ImageKnobDemoState->load() << "TESTYTEST666420" << '\n';
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

//    getAPVTSParams();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
    }
}

//==============================================================================
bool AntimatterUITemplateAudioProcessor::hasEditor() const
{
    return true; 
}

juce::AudioProcessorEditor* AntimatterUITemplateAudioProcessor::createEditor()
{
    return new AntimatterUITemplateAudioProcessorEditor (*this);
}

//==============================================================================
void AntimatterUITemplateAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = APVTS.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void AntimatterUITemplateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (APVTS.state.getType()))
            APVTS.replaceState (juce::ValueTree::fromXml (*xmlState));
}

//void getStateInformation (juce::MemoryBlock& destData) override
//{
//    auto state = parameters.copyState();
//    std::unique_ptr<juce::XmlElement> xml (state.createXml());
//    copyXmlToBinary (*xml, destData);
//}

//void setStateInformation (const void* data, int sizeInBytes) override
//{
//    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
//
//    if (xmlState.get() != nullptr)
//        if (xmlState->hasTagName (parameters.state.getType()))
//            parameters.replaceState (juce::ValueTree::fromXml (*xmlState));
//}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AntimatterUITemplateAudioProcessor();
}
