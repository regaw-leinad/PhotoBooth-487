#pragma once

#include "FrameHandler.h"
#include <string>

class LaplacianFilterFrameHandler : public FrameHandler {
public:
	LaplacianFilterFrameHandler() {}
	~LaplacianFilterFrameHandler() {}

	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);

	std::string getName() const {
		return "Laplacian";
	}
};

