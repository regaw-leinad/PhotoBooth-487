/*
	DrawFrameHandler
	Author: Dan Wager

	A FrameHandler that allows drawing on top of the frame.
	When the drawing is complete, it will follow the face around.
*/

#include "DrawFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

DrawFrameHandler::DrawFrameHandler() {
	this->mouseDown = false;
	this->faceX = 0;
	this->faceY = 0;
}

/*
*  Handles a frame of the webcam capture with face detection. Handles the rendering 
*  of the drawings.
*  Pre:		faces is a valid vector containing faces
*  Post:	a rectangle is drawn around all the detected faces
*/
void DrawFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) {
	// If we have at least one face, use the first face
	// to update our global faceX/Y for use with mouse events
	if (faces.size() > 0) {
		this->faceX = faces[0].getFace().x;
		this->faceY = faces[0].getFace().y;
	}

	// Render all our stored drawings in GREEN
	for (size_t i = 0; i < this->drawings.size(); i++) {
		Drawing drawing = this->drawings[i];
		
		vector<Point> points = this->drawings[i].getDrawing();
		if (points.size() > 1) {
			for (size_t i = 1; i < points.size(); i++) {
				Point p1(points[i - 1]);
				Point p2(points[i]);

				p1.x += this->faceX - drawing.getPivot().x;
				p1.y += this->faceY - drawing.getPivot().y;

				p2.x += this->faceX - drawing.getPivot().x;
				p2.y += this->faceY - drawing.getPivot().y;

				// Draw lines between each point in the drawing
				line(frame, p1, p2, Scalar(0, 255, 0), 2);
			}
		}
	}

	// If the mouse is down, render the current drawing in RED
	if (this->mouseDown) {
		vector<Point> currentPoints = this->currentDrawing.getDrawing();
		if (currentPoints.size() > 1) {
			for (size_t i = 1; i < currentPoints.size(); i++) {
				line(frame, currentPoints[i - 1], currentPoints[i], Scalar(0, 0, 255), 2);
			}
		}
	}
}

/*
*  Handles mouse move events
*  Pre:		eventCode must be a valid MouseEvent code
*  Post:	None
*/
void DrawFrameHandler::onMouseEvent(int eventCode, int x, int y, int flags) {
	switch (eventCode) {
		case CV_EVENT_LBUTTONDOWN:
			// Start of a new drawing
			this->mouseDown = true;
			this->currentDrawing.addPoint(Point(x, y));
			break;
		case CV_EVENT_LBUTTONUP:
			// End of the current drawing
			this->mouseDown = false;
			// Set our pivot point to the current x,y of the face
			this->currentDrawing.setPivot(Point(this->faceX, this->faceY));
			// Add a copy to our drawings collection
			this->drawings.push_back(Drawing(this->currentDrawing));
			// Clear the current drawing!
			this->currentDrawing.clear();
			break;
		case CV_EVENT_MOUSEMOVE:
			// Only update current drawing if mouse is down
			if (this->mouseDown) {
				this->currentDrawing.addPoint(Point(x, y));
			}
			break;
		case CV_EVENT_RBUTTONDOWN:
			// If we're not drawing and we have at least one, undo
			if (!this->mouseDown && this->drawings.size() > 0) {
				this->drawings.pop_back();
			}
			break;
		default:
			break;
	}
}

/*
*  Gets the name of this FrameHandler
*  Pre:		None
*  Post:	Returns the name of this FrameHandler
*/
string DrawFrameHandler::getName() const {
	return "Drawing";
}
