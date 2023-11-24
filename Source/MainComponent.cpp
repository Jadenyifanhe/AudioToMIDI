#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
    : params("Parameters"),
      fileWindowComponent(params),
      paramPanel(params),
      midiOutput(params) {
    setSize (700, 500);
    addAndMakeVisible(fileWindowComponent);
    addAndMakeVisible(paramPanel);
    addAndMakeVisible(midiOutput);
}

MainComponent::~MainComponent() {}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    fileWindowComponent.setBounds(0, 0, getWidth() / 2, getHeight() / 3);
    paramPanel.setBounds(0, getHeight() / 3, getWidth(), getHeight() * 2 / 3);
    midiOutput.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight() / 3);
}
