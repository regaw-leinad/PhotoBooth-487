/*
	DrawFrameHandler
	Author: Dan Wager

	A FrameHandler that allows drawing on top of the frame.
	When the drawing is complete, it will follow the face around.
*/

#pragma once

#include "FaceDetectionFrameHandler.h"
#include "Drawing.h"

#include <vector>

class DrawFrameHandler : public FaceDetectionFrameHandler {
public:
	DrawFrameHandler();
	~DrawFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture with face detection. Handles the rendering 
	*  of the drawings.
	*  Pre:		faces is a valid vector containing faces
	*  Post:	a rectangle is drawn around all the detected faces
	*/
	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName);
	
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
	Drawing currentDrawing;
	std::vector<Drawing> drawings;

	// Is the mouse down or not
	bool mouseDown;
	int faceX;
	int faceY;
};
