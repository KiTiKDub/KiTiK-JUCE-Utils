include(FetchContent)
FetchContent_Declare(
  juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE
  GIT_TAG master
  GIT_SHALLOW ON
)
FetchContent_MakeAvailable(juce)

add_library(
	kitik-utils
	KitikUtility/DSP/overSampleGain.h
	KitikUtility/DSP/overSampleGain.cpp
	KitikUtility/GUI/dragToDawButton.h
	KitikUtility/GUI/LookAndFeel.h
	KitikUtility/GUI/LookAndFeel.cpp
	KitikUtility/GUI/PresetManager.h
	KitikUtility/GUI/PresetManager.cpp
	KitikUtility/GUI/PresetPanel.h
	KitikUtility/GUI/PresetPanel.cpp
	KitikUtility/GUI/RotarySliderWithLabels.h
	KitikUtility/GUI/RotarySliderWithLabels.cpp
	KitikUtility/GUI/SliderWithLabels.h
	KitikUtility/GUI/SliderWithLabels.cpp
	KitikUtility/GUI/Toolbar.h
	KitikUtility/GUI/Toolbar.cpp
	KitikUtility/Utility/AsyncUpdater.h
	KitikUtility/Utility/BrowserComponent.h
	KitikUtility/DSP.h
	KitikUtility/GUI.h
	KitikUtility/Utility.h
	KitikUtilityHeader.h )

target_include_directories(juce PRIVATE ${juce_SOURCE_DIR})