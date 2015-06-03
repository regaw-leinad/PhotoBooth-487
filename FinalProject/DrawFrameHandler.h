#pragma once

#include "FrameHandler.h"
#include <vector>

class DrawFrameHandler : public FrameHandler {
public:
	DrawFrameHandler();
	~DrawFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture with face detection
	*  Pre:		faces is a valid vector containing faces
	*  Post:	a rectangle is drawn around all the detected faces
	*/
	//void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName);
	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);
	/*
	*  Handles mouse move events
	*  Pre:		eventCode must be a valid MouseEvent code
	*  Post:	None
	*/
	void onMouseEvent(int eventCode, int x, int y, int flags);

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const;

private:
	std::vector<cv::Rect> rectangles;
	cv::Rect currentRect;
	cv::Point2d p1;
	cv::Point2d p2;
	bool mouseDown;
	int dX, dY;
};

