#include "Autodafe.hpp"
#include <math.h>
#include "dsp/digital.hpp"
#include "dsp/decimator.hpp"
#include "dsp/fft.hpp"
#include "dsp/filter.hpp"
#include "dsp/fir.hpp"
#include "dsp/frame.hpp"
#include "dsp/minblep.hpp"
#include "dsp/ode.hpp"
#include "dsp/ringbuffer.hpp"
#include "dsp/samplerate.hpp"

Plugin *plugin;

extern Model *modelSnare;
extern Model *modelKick;
extern Model *modelClaps;
extern Model *modelCymbals;
extern Model *modelRide;
extern Model *modelRimClaves;
extern Model *modelHiHatClosed;
extern Model *modelHiHatOpen;
extern Model *modelMixer;

void init(rack::Plugin *p) {
	plugin = p;
	plugin->slug = "Autodafe-DrumKit";
    #ifdef VERSION
    p->version = TOSTRING(VERSION);
    #endif

    p->addModel(modelSnare);
    p->addModel(modelKick);
    p->addModel(modelClaps);
    p->addModel(modelCymbals);
    p->addModel(modelRide);
    p->addModel(modelRimClaves);
    p->addModel(modelHiHatClosed);
    p->addModel(modelHiHatOpen);
    p->addModel(modelMixer);

	}

