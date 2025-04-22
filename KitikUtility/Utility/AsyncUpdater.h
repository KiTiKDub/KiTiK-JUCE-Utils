#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

namespace kitik
{
    struct AsyncUpdater : public juce::AsyncUpdater
    {
        KiTiKAsyncUpdater() {};

        void setCallback(std::function<void(void)> callback)
        {
            callback_ = std::move(callback);
        }

        void handleAsyncUpdate() override
        {
            callback_();
        }

    private:
        std::function<void(void)> callback_;
    };
} // namespace name

