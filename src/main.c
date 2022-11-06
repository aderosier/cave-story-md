#include "common.h"

#include "audio.h"
#include "md/dma.h"
#include "effect.h"
#include "md/error.h"
#include "gamemode.h"
#include "md/joy.h"
#include "md/stdlib.h"
#include "resources.h"
#include "stage.h"
#include "system.h"
#include "md/comp.h"
#include "tsc.h"
#include "md/sys.h"
#include "md/vdp.h"
#include "md/xgm.h"

volatile uint8_t ready;

uint8_t gamemode;
uint8_t paused;
uint8_t gameFrozen;

void aftervsync() {
	disable_ints();
    z80_pause_fast();

    vdp_fade_step_dma();
	dma_flush();
	dqueued = FALSE;
	if(ready) {
		if(inFade) vdp_sprites_clear();
        //if(gamemode == GM_GAME) stage_update(); // Scrolling
		vdp_sprites_update();
		ready = FALSE;
	}

    z80_resume();
    enable_ints();

    vdp_fade_step_calc();
    joy_update();
}

__attribute__((noreturn))
void main() {
    srand(0xC427); // initiate rand number generator
    mem_init();
    vdp_init();
	xgm_init();
    system_init();
    stageBackground = 0xFF;
	if(system_checkdata() != SRAM_INVALID) {
		system_load_config();
	}
    //dma_clear();
	joy_init();
	enable_ints();
    // Initialize time and speed tables (framerate adjusted)
    if(pal_mode) {
		time_tab = time_tab_pal;
        speed_tab = speed_tab_pal;
	} else {
        time_tab = time_tab_ntsc;
        speed_tab = speed_tab_ntsc;
	}
    // let's the fun go on !
    
    sound_init();
	
	// Error Tests
	//__asm__("move.w (1),%d0"); // Address Error
	//__asm__("illegal"); // Illegal Instruction
	//__asm__("divu #0,%d0"); // Zero Divide
	//error_oom(); // Out of memory
	//error_other("Test test!\nTest!"); // Fatal message

	splash_main();
	intro_main();
    while(TRUE) {
		uint8_t select = titlescreen_main();
		if(select == 0) {
			select = saveselect_main();
			if(select >= 4) continue;
			game_main(select);
			credits_main();
		} else if(select == 2) {
			soundtest_main();
		} else if(select == 3) {
			config_main();
		} else {
			game_main(select);
			credits_main();
		}
    }
}
