/*
	FPS
	Author: Dan Wager

	This class keeps track of average FPS
*/

#include "FPS.h"

#include <time.h>

int FPS::fpsStart = 0;
double FPS::averageFps = 0;
double FPS::fps1Sec = 0;

/*
*  Gets the average FPS
*  Pre:		None
*  Post:	Returns the average FPS
*/
int FPS::getAverageFPS() {
	if (clock() - fpsStart > 1000) {
		fpsStart = clock();
		averageFps = 0.7 * averageFps + 0.3 * fps1Sec;
		fps1Sec = 0;
	}

	fps1Sec++;
	return averageFps;
}
