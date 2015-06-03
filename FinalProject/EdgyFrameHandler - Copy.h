/*
	EdgyFrameHandler
	Author: Dan Wager

	This class filters a frame with an edge detection filter
*/

#pragma once

#include "FrameHandler.h"
#include <string>

class EdgyFrameHandler : public FrameHandler {
public:
	EdgyFrameHandler() {}
	~EdgyFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture
	*  Pre:		None
	*  Post:	frame is filtered with an edge detection filter
	*/
	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const {
		return "Edgy";
	}
};

