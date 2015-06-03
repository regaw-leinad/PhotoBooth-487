/*
	FPS
	Author: Dan Wager

	This class keeps track of average FPS
*/
#pragma once

class FPS {
public:
	/*
	*  Gets the average FPS
	*  Pre:		None
	*  Post:	Returns the average FPS
	*/
	static int getAverageFPS();

private:
	static int fpsStart;
	static double averageFps;
	static double fps1Sec;
};

