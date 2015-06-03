/*
	FaceTextFrameHandler
	Author: Dan Wager

	This class draws text that is centered around the detected face's foreheads.
	It extends from FaceDetectionFrameHandler for the facial detection.
*/

#include "FaceTextFrameHandler.h"
#include <iostream>

using namespace std;
using namespace cv;

FaceTextFrameHandler::FaceTextFrameHandler() {
	this->text = "";
}

/*
*  Handles a frame of the webcam capture with face detection
*  Pre:		faces is a valid vector containing faces
*  Post:	a rectangle is drawn around all the detected faces
*/
void FaceTextFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) {
	if (keyPressed == Keys::KEY_DELETE) {
		// "delete" the last character of the text if any
		if (this->text.length() > 0) {
			this->text = this->text.substr(0, text.length() - 1);
		}
		return;
	}

	if (keyPressed != Keys::KEY_NONE) {
		if (keyPressed == Keys::KEY_SPACE ||
			keyPressed >= Keys::KEY_A_LOWER && keyPressed <= Keys::KEY_Z_LOWER ||
			keyPressed >= Keys::KEY_A_UPPER && keyPressed <= Keys::KEY_Z_UPPER) {\
			// [a-zA-Z ] adds to string
			this->text += (char)keyPressed;
		}
	}

	// Render text on each face
	for (size_t i = 0; i < faces.size(); i++) {
		Rect face = faces[i].getFace();

		int baseline = 0;
		// Calculate text box size
		Size textSize = getTextSize(this->text, FONT_HERSHEY_COMPLEX_SMALL, 1.5, 2, &baseline);

		// Get x-offset for centering
		int xOffset = (face.x + textSize.width / 2) - (face.x + face.width / 2);
		// Create the point with +25 y-offset
		Point newPoint(face.x - xOffset, face.y + 25);

		// Render text
		putText(frame, this->text, newPoint, FONT_HERSHEY_COMPLEX_SMALL, 1.5, Scalar(0, 0, 255), 2);
	}
}

/*
*  Gets the name of this FrameHandler
*  Pre:		None
*  Post:	Returns the name of this FrameHandler
*/
string FaceTextFrameHandler::getName() const {
	return "Face Text";
}
