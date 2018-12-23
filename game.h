typedef struct {

    /* position */
	int worldX;
	int worldY;
    int screenX;
    int screenY;
    
    /* movement */
    int deltaX;
    int deltaY;
    int moving; // unused if accel is implemented

    /* size */
	int width;
    int height;

    /* animation */
    int aniCounter;
    int aniSpeed;
    int baseState;
    int baseFrame;
    int aniState;
    int curFrame;
    int numFrames;
    int palRow;

} SPRITE;

/* Prototypes */

// init
void initGame();

// update
void updateGame();

// draw
void drawGame();
void drawSprite(SPRITE *s, int shadowOAMIndex);

// util
void animateSprite(SPRITE *s);