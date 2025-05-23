/*
  ==============================================================================

    rotarySliderWithLabels.h
    Created: 6 Nov 2023 5:57:57pm
    Author:  kylew

  ==============================================================================
*/

#pragma once
#include "juce_gui_basics/juce_gui_basics.h"
#include "juce_audio_processors/juce_audio_processors.h"

namespace kitik
{
    struct RotarySliderWithLabels : juce::Slider {
        RotarySliderWithLabels(juce::RangedAudioParameter* rap, const juce::String& unitSuffix, const juce::String title) :
            juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox),
            param(rap),
            suffix(unitSuffix)
        {
            setName(title);
        }

        struct LabelPos {
            int pos;
            juce::String label;
            int fontSize;

        };

        juce::Array<LabelPos> labels;

        void paint(juce::Graphics& g) override;
        juce::Rectangle<int> getSliderBounds() const;

        void changeParam(juce::RangedAudioParameter* p);

    protected:
        juce::RangedAudioParameter* param;
        juce::String suffix;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithLabels)
    };

    template <
        typename Attachment,
        typename APVTS,
        typename ParamName,
        typename SliderType
    >
    void makeAttachment(std::unique_ptr<Attachment>& attachment,
        APVTS& apvts,
        const ParamName& name,
        SliderType& slider)
    {
        attachment = std::make_unique<Attachment>(apvts,
            name,
            slider);
    }

    template <
        typename APVTS,
        typename Name
    >
    juce::RangedAudioParameter& getParam(APVTS& apvts, const Name& name)
    {
        auto param = apvts.getParameter(name);

        return *param;
    }

    juce::String getValString(const juce::RangedAudioParameter& param, bool getLow, juce::String suffix, std::vector<juce::String>);

    template <
        typename Labels,
        typename ParamType,
        typename SuffixType
    >
    void addLabelPairs(Labels& labels, const int posOne, const int posTwo, const ParamType& param, const SuffixType& suffix, const int fontSizeTop = 14, const int fontSizeBottom = 14, std::vector<juce::String> array = std::vector<juce::String>())
    {
        labels.clear();
        labels.add({ posOne, getValString(param, true, suffix, array), fontSizeTop });
        labels.add({ posTwo, getValString(param, false, suffix, array), fontSizeBottom });
    }
}


