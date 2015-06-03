/*
	DummyFrameHandler
	Author: Dan Wager

	This class is a frame handler that does not modify any frames.
*/

#pragma once

#include "FrameHandler.h"
#include <string>

class DummyFrameHandler : public FrameHandler {
public:
	DummyFrameHandler() {}
	~DummyFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture
	*  Pre:		None
	*  Post:	Nothing is modified in frame
	*/
	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {}

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const {
		return "Default";
	}
};

