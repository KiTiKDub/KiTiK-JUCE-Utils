/*
  ==============================================================================

    dragToDawButton.h
    Created: 13 Aug 2024 6:18:01pm
    Author:  kylew

  ==============================================================================
*/

#pragma once

#include "juce_gui_basics/juce_gui_basics.h"

namespace kitik
{
  struct dragToDawButton : public juce::TextButton
  {
      dragToDawButton() {}
      ~dragToDawButton() override {}
      
      //void paint(juce::Graphics& g) override {}
      //void resized() override {}

      void mouseDrag(const juce::MouseEvent& e) override
      {
          if (onDrag != nullptr)
              onDrag(*this, e);
      }

      std::function<void(dragToDawButton&, const juce::MouseEvent&)> onDrag;
  };
}