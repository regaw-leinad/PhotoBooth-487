/*
	LaplacianFilterFrameHandler
	Author: Dan Wager

	This class filters a frame with a Laplacian filter
*/

#pragma once

#include "FrameHandler.h"

#include <string>

class LaplacianFilterFrameHandler : public FrameHandler {
public:
	LaplacianFilterFrameHandler() {}
	~LaplacianFilterFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture
	*  Pre:		None
	*  Post:	frame is filtered with a laplacian filter
	*/
	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const {
		return "Laplacian";
	}
};
