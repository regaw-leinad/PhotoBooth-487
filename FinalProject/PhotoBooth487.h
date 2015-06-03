#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Keys.h"
#include "FrameHandler.h"

#include <unordered_map>

class PhotoBooth487 {
public:
	static const char *WINDOW_NAME;

	PhotoBooth487(const int &camWidth, const int &camHeight);
	~PhotoBooth487();

	static void onMouseEvent(int eventCode, int x, int y, int flags, void *param);

	void start();

private:
	CvCapture *camera;
	bool loaded;
	std::unordered_map<int, FrameHandler*> frameHandlers;
	FrameHandler *currentFrameHandler;

	bool initCamera(const int &camWidth, const int &camHeight);
	void initWindow();
	void initHandlers();
};

