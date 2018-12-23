#include "lib.h"
#include "state.h"

/* prototypes */
void init();

/* input variables */
u16 buttons;
u16 oldButtons;

/* seed for psuedo randomization */
int seed;

/* shadow OAM for double buffering */
OBJ_ATTR shadowOAM[128];

void init() {
	buttons = BUTTONS;
	goToStartState();
}

int main(void) {
    init();
	while(1)
	{
        /* update input variables */
        oldButtons = buttons;
        buttons = BUTTONS;

        state();
	}

	return 0; /* terminate */
}