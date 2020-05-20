#include "Autodafe.hpp"
#include "hhopen.h"
#include "dsp/digital.hpp"


struct DrumsHiHatOpen : Module {
	enum ParamIds {
        SAMPLETYPE,
     
		NUM_PARAMS
	};
	enum InputIds {
		TRIG_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		AUDIO_OUTPUT,
		NUM_OUTPUTS
	};
    int numsamples = 8;
	SchmittTrigger trigger;
	SchmittTrigger sampletypeselector;
    int sampletype = 1;
      unsigned int count1 = 0;
    unsigned int count2 = 0;
    unsigned int count3 = 0;
     unsigned int count4 = 0;
     unsigned int count5 = 0;
     unsigned int count6 = 0;
     unsigned int count7 = 0;
     unsigned int count8 = 0;

	
	DrumsHiHatOpen();
	void step();





    json_t *toJson() {
                json_t *rootJ = json_object();

                json_object_set_new(rootJ, "sampletype", json_integer(sampletype));

                return rootJ;
        }

        void fromJson(json_t *rootJ) {
                json_t *stateJ = json_object_get(rootJ, "sampletype");
                if (stateJ) {
                        sampletype = json_integer_value(stateJ);
                }
        }


    
};

DrumsHiHatOpen::DrumsHiHatOpen() : Module(NUM_PARAMS,NUM_INPUTS,NUM_OUTPUTS,9)
{
	// disarm
    
    count1  = HHOP_sample1_len;
    count2  = HHOP_sample2_len;
    count3  = HHOP_sample3_len;
    count4  = HHOP_sample4_len;
    count5  = HHOP_sample5_len;
    count6  = HHOP_sample6_len;
    count7  = HHOP_sample7_len;
    count8  = HHOP_sample8_len;
   
}








void DrumsHiHatOpen::step()
{
    
    
    lights[0].value -= lights[0].value / 0.75 / engineGetSampleRate();
   
    
    if (sampletypeselector.process(params[SAMPLETYPE].value))
    { lights[0].value = 1.0;
         if (sampletype<numsamples) {
        sampletype++;
            
         }
        else
        {
            sampletype=1;
        }
    }
    for (int i = 0; i < numsamples; i++) {
        lights[1+i].value=0.0;
  
        lights[1+sampletype-1].value=1.0;
    }
   
    
    if (trigger.process(inputs[TRIG_INPUT].value)) {
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        count6 = 0;
        count7 = 0;
        count8 = 0;
        lights[0].value = 1;
    }

    
    
	if (sampletype == 1)
    {
                if( count1 < HHOP_sample1_len ) {
                    int16_t sample;
                    sample  = HHOP_sample1[count1++];
                    sample |= HHOP_sample1[count1++] << 8;
                    
                    outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample1_len  ;
                } else {
                    outputs[AUDIO_OUTPUT].value= 0.0 ;
                }
    }
    
    
    
    
    if (sampletype == 2)
    {
        if( count2 < HHOP_sample2_len ) {
            int16_t sample;
            sample  = HHOP_sample2[count2++];
            sample |= HHOP_sample2[count2++] << 8;
            
            outputs[AUDIO_OUTPUT].value=5.0 * (float)sample / HHOP_sample2_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    if (sampletype == 3)
    {
        if( count3 < HHOP_sample3_len ) {
            int16_t sample;
            sample  = HHOP_sample3[count3++];
            sample |= HHOP_sample3[count3++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample3_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    
    
    
    if (sampletype == 4)
    {
        if( count4 < HHOP_sample4_len ) {
            int16_t sample;
            sample  = HHOP_sample4[count4++];
            sample |= HHOP_sample4[count4++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample4_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    if (sampletype == 5)
    {
        if( count5 < HHOP_sample5_len ) {
            int16_t sample;
            sample  = HHOP_sample5[count5++];
            sample |= HHOP_sample5[count5++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample5_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    if (sampletype == 6)
    {
        if( count6 < HHOP_sample6_len ) {
            int16_t sample;
            sample  = HHOP_sample6[count6++];
            sample |= HHOP_sample6[count6++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample6_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
    
    if (sampletype == 7)
    {
        if( count7 < HHOP_sample7_len ) {
            int16_t sample;
            sample  = HHOP_sample7[count7++];
            sample |= HHOP_sample7[count7++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample7_len ;
        } else {
            outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
   
    
    
    
    if (sampletype == 8)
    {
        if( count8 < HHOP_sample8_len ) {
            int16_t sample;
            sample  = HHOP_sample8[count8++];
            sample |= HHOP_sample8[count8++] << 8;
            
            outputs[AUDIO_OUTPUT].value= 5.0 * (float)sample / HHOP_sample8_len ;
        } else {
           outputs[AUDIO_OUTPUT].value= 0.0 ;
        }
    }
    
    
}

struct DrumsHiHatOpenWidget : ModuleWidget
{
DrumsHiHatOpenWidget(DrumsHiHatOpen *module) : ModuleWidget(module)
{
	setPanel(SVG::load(assetPlugin(plugin, "res/DrumsHiHatOpen.svg")));

	addChild(createScrew<ScrewSilver>(Vec(15,   0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsHiHatOpen::SAMPLETYPE, 0.0, 1.0, 0.0));
    
    //addParam(createParam<Davies1900hBlackKnob>(Vec(30, 80), module, DrumsHiHatOpen::PITCH, -12, 12.0, 0.0));
    
     
    
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(26,65), module, 0));
    
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,100), module, 1));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,125), module, 2));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,150), module, 3));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,175), module, 4));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,200), module, 5));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,225), module, 6));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,250), module, 7));
    addChild(ModuleLightWidget::create<SmallLight<GreenLight>>(Vec(10,275), module, 8));

    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsHiHatOpen::TRIG_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(30, 300), module, DrumsHiHatOpen::AUDIO_OUTPUT));

}
};

Model *modelHiHatOpen = Model::create<DrumsHiHatOpen,DrumsHiHatOpenWidget>("Autodafe-DrumKit", "Drums - Open Hats", "Open Hats",DRUM_TAG);
