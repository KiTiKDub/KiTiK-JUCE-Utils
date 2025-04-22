#pragma once
#include "juce_gui_basics/juce_gui_basics.h"

namespace kitik
{
    struct BrowserComp : public juce::FileBrowserComponent
    {
        using juce::FileBrowserComponent::FileBrowserComponent;

        void fileClicked(const juce::File& file, const juce::MouseEvent& e) override
        {
            clickedFile = file;
            fileReloaded = true;
        }

        juce::File clickedFile{ juce::File() };
        bool fileReloaded{ false };
    };
}