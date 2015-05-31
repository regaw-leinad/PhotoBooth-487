#pragma once

#include "FrameHandler.h"
#include <string>

class DummyFrameHandler : public FrameHandler {
public:
	DummyFrameHandler() {}
	~DummyFrameHandler() {}

	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {}

	std::string getName() const {
		return "Default";
	}
};

