/*
	EdgyFrameHandler
	Author: Dan Wager

	This class filters a frame with an edge detection filter
*/

#include "EdgyFrameHandler.h"

using namespace cv;

/*
*  Handles a frame of the webcam capture
*  Pre:		None
*  Post:	frame is filtered with an edge detection filter
*/
void EdgyFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	// Blur to reduce noise
	GaussianBlur(frame, frame, Size(7, 7), 2.0, 2.0);
	// Apply filter
	Canny(frame, frame, 20, 60);
}
