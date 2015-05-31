#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Keys.h"

#include <string>

class FrameHandler {
public:
	FrameHandler() {}
	virtual ~FrameHandler() {}

	virtual void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) = 0;
	virtual std::string getName() const = 0;
};

