/*
	LaplacianFilterFrameHandler
	Author: Dan Wager

	This class filters a frame with a Laplacian filter
*/

#include "LaplacianFilterFrameHandler.h"

using namespace cv;

/*
*  Handles a frame of the webcam capture
*  Pre:		None
*  Post:	frame is filtered with a laplacian filter
*/
void LaplacianFilterFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	// Blur to reduce noise
	GaussianBlur(frame, frame, Size(3, 3), 0);
	// Convert to greyscale
	cvtColor(frame, frame, CV_BGR2GRAY);
	// Apply filter
	Laplacian(frame, frame, CV_16S, 3);
	convertScaleAbs(frame, frame);
}
