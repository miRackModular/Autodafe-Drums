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

void init(rack::Plugin *p) {
	plugin = p;
	plugin->slug = "Autodafe - Drum Kit";
    #ifdef VERSION
    p->version = TOSTRING(VERSION);
    #endif
		
        // createModel<DrumsKickWidget>(plugin, "Drums - Kick", "Drums - Kick");
    p->addModel(modelSnare);
    p->addModel(modelKick);
        
        // createModel<DrumsHiHatClosedWidget>(plugin, "Drums - Closed Hats", "Drums - Closed Hats");
        // createModel<DrumsHiHatOpenWidget>(plugin, "Drums - Open Hats", "Drums - Open Hats");

        
        // createModel<DrumsClapsWidget>(plugin, "Drums - Claps", "Drums - Claps");
        // createModel<DrumsCymbalsWidget>(plugin, "Drums - Cymbals", "Drums - Cymbals");
        // createModel<DrumsRideWidget>(plugin, "Drums - Ride", "Drums - Ride");
        // createModel<DrumsRimClavesWidget>(plugin, "Drums - Rim/Claves", "Drums - Rim/Claves");
     // createModel<DrumsMixerWidget>(plugin, "Drums - 8-Channel Mixer", "Drums - 8-Channel Mixer");

		printf("%p %p\n", plugin, &plugin);
		

	}

