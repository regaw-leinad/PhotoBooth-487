/*
	FrameHandler
	Author: Dan Wager

	This is the base class for all classes that want to handle and modify a frame
	of the webcam capture.
	To extend this class, you must implement handleFrame() and getName()
*/

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

	/*
	*  Handles a frame of the webcam capture
	*  Pre:		None
	*  Post:	frame is modifed
	*/
	virtual void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) = 0;
	
	/*
	*  Handles mouse move events
	*  Pre:		eventCode must be a valid MouseEvent code
	*  Post:	None
	*/
	virtual void onMouseEvent(int eventCode, int x, int y, int flags) {}

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	virtual std::string getName() const = 0;
};

