/*
	LaplacianFilterFrameHandler
	Author: Dan Wager

	This class filters a frame with a Laplacian filter
*/

#include "LaplacianFilterFrameHandler.h"

using namespace cv;

void LaplacianFilterFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	GaussianBlur(frame, frame, Size(3, 3), 0);
	cvtColor(frame, frame, CV_BGR2GRAY);
	Laplacian(frame, frame, CV_16S, 3);
	convertScaleAbs(frame, frame);
}
