#include "game.h"
#include "lib.h"

void animateSprite(SPRITE *s) {
    if (++s->aniCounter % s->aniSpeed == 0) {
        s->curFrame += (s->height / 8);
        if (s->curFrame == s->baseFrame + s->numFrames) {
            s->curFrame = s->baseFrame;
        }
    }
}

// this is a mess but just reconciles the sprite's size and shape against its dimensions
void drawSprite(SPRITE *s, int shadowOAMIndex) {
    if (!(s->screenX + s->width < 0) && !(s->screenX > SCREENWIDTH) && !(s->screenY + s->height < 0) && !(s->screenY > SCREENHEIGHT)) {
        // sprite is on screen and drawable

        if (s->height == s->width) {
            shadowOAM[shadowOAMIndex].attr0 = (ROWMASK & s->screenY) | ATTR0_4BPP | ATTR0_SQUARE;
            switch (s->width) {
                case 8:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_TINY;
                    break;
                case 16:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_SMALL;
                    break;
                case 32:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_MEDIUM;
                    break;
                case 64:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_LARGE;
                    break;
                default:
                    break;
            }
        } else if (s->height > s->width) {
            shadowOAM[shadowOAMIndex].attr0 = (ROWMASK & s->screenY) | ATTR0_4BPP | ATTR0_TALL;
            switch (s->width) {
                case 8:
                    if (s->height == 16) {
                        shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_TINY;
                    } else {
                        shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_SMALL;
                    }
                    break;
                case 16:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_MEDIUM;
                    break;
                case 32:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_LARGE;
                    break;
                default:
                    break;
            }
        } else {
            shadowOAM[shadowOAMIndex].attr0 = (ROWMASK & s->screenY) | ATTR0_4BPP | ATTR0_WIDE;
            switch (s->width) {
                case 16:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_TINY;
                    break;
                case 32:
                    if (s->height == 8) {
                        shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_SMALL;
                    } else {
                        shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_MEDIUM;
                    }
                    break;
                case 64:
                    shadowOAM[shadowOAMIndex].attr1 = (COLMASK & s->screenX) | ATTR1_LARGE;
                    break;
                default:
                    break;
            }
        }
        shadowOAM[shadowOAMIndex].attr2 = ATTR2_PALROW(s->palRow) | ATTR2_TILEID(s->curFrame, s->aniState);
    } else {
        // sprite off screen, disabled, or otherwise hidden
        shadowOAM[shadowOAMIndex].attr0 = ATTR0_HIDE;
    }
}