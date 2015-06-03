#include "EdgyFrameHandler.h"

using namespace cv;

void EdgyFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	GaussianBlur(frame, frame, Size(7, 7), 2.0, 2.0);
	Canny(frame, frame, 20, 60);
}
