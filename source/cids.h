//------------------------------------------------------------------------
// Copyright(c) 2023 .
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID kMIDIOutputExampleProcessorUID (0x6B3E46C9, 0xB8F959FB, 0xB1C3E8F0, 0x2691CD64);
static const Steinberg::FUID kMIDIOutputExampleControllerUID (0xF999FEED, 0x726750DF, 0x8F2BCE0E, 0xCDF6DE72);

#define MIDIOutputExampleVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace MyCompanyName
