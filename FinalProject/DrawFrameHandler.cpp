#include "DrawFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

DrawFrameHandler::DrawFrameHandler() {
	this->currentRect = Rect(0, 0, 0, 0);
	this->p1 = Point(0, 0);
	this->p2 = Point(0, 0);

	this->mouseDown = false;
}

//void DrawFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) {
void DrawFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	for (size_t i = 0; i < this->rectangles.size(); i++) {
		Rect rect = this->rectangles[i];
		rectangle(frame, rect, Scalar(0, 255, 0), 3);
	}

	if (this->mouseDown) {
		rectangle(frame, Rect(this->p1, this->p2), Scalar(0, 0, 255), 3);
	}
}

void DrawFrameHandler::onMouseEvent(int eventCode, int x, int y, int flags) {
	switch (eventCode) {
		case CV_EVENT_LBUTTONDOWN:
			this->mouseDown = true;

			this->p1.x = x;
			this->p1.y = y;
			this->p2.x = x;
			this->p2.y = y;
			break;
		case CV_EVENT_LBUTTONUP:
			this->mouseDown = false;

			this->p2.x = x;
			this->p2.y = y;

			this->rectangles.push_back(Rect(p1, p2));
			break;
		case CV_EVENT_MOUSEMOVE:
			if (this->mouseDown) {
				this->p2.x = x;
				this->p2.y = y;
			}
			break;
		default:
			break;
	}
}

string DrawFrameHandler::getName() const {
	return "Draw";
}
