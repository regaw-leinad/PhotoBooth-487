#pragma once

#include "FrameHandler.h"
#include <string>

class EdgyFrameHandler : public FrameHandler {
public:
	EdgyFrameHandler() {}
	~EdgyFrameHandler() {}

	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);

	std::string getName() const {
		return "Edgy";
	}
};

