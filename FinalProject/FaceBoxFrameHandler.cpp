/*
	FaceBoxFrameHandler
	Author: Dan Wager

	This class draws a rectangle around a detected face.
	It extends from FaceDetectionFrameHandler for the facial detection.
*/

#include "FaceBoxFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

/*
*  Handles a frame of the webcam capture with face detection
*  Pre:		faces is a valid vector containing faces
*  Post:	a rectangle is drawn around all the detected faces
*/
void FaceBoxFrameHandler::handleFaceDetectionFrame(Mat &frame, const int &keyPressed, const vector<Face> &faces, const char *windowName) {
	for (size_t i = 0; i < faces.size(); i++) {
		Face face = faces[i];

		rectangle(frame, face.getFace(), Scalar(0, 255, 0), 4);
	}
}

/*
*  Gets the name of this FrameHandler
*  Pre:		None
*  Post:	Returns the name of this FrameHandler
*/
string FaceBoxFrameHandler::getName() const {
	return "Face Box";
}
