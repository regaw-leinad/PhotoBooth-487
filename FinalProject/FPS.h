#pragma once
class FPS {
public:
	static int getAverageFPS();

private:
	static int fpsStart;
	static double averageFps;
	static double fps1Sec;
};

