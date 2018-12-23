#include "lib.h"
#include "state.h"
#include "game.h"

/* state machine */
void (*state)();

/* === START === */

void startState() {
    waitForVBlank();
    if (BUTTON_PRESSED(BUTTON_START)) {
        // initGame();
        goToGameState();
    }
}

void goToStartState() {
    REG_DISPCTL = MODE3 | BG2_ENABLE;

    hideSprites();
    fillScreen3(GREEN);

    state = startState;
}

/* === GAME === */

void gameState() {
    // updateGame();
    // drawGame();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);
    if (BUTTON_PRESSED(BUTTON_A)) {
        goToStartState();
    }
}

void goToGameState () {
    // /* any of the bg's palettes should include all colors needed */
    // DMANow(3, boardwalk_sandPal, PALETTE, 256);

    // /* load in foreground */
    // DMANow(3, boardwalk_sandTiles, &CHARBLOCK[0], boardwalk_sandTilesLen);
    // DMANow(3, boardwalk_sandMap, &SCREENBLOCK[31], 1024);

    //  load in foreground 
    // DMANow(3, boardwalk_waterTiles, &CHARBLOCK[1], boardwalk_waterTilesLen);
    // DMANow(3, boardwalk_waterMap, &SCREENBLOCK[30], 1024);

    // /* load in spritesheet */
    // DMANow(3, spritesheetPal, SPRITEPALETTE, 256);
    // DMANow(3, spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);

    REG_DISPCTL = MODE0 | BG0_ENABLE | BG1_ENABLE | SPRITE_ENABLE;

    state = gameState;
}
