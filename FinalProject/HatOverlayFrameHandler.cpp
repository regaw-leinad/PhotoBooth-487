/*
	HatOverlayFrameHandler
	Author: Dan Wager

	Detects a face and puts a hat on their head!
	Extends ImageOverlayFrameHandler to provide the image.
*/

#include "HatOverlayFrameHandler.h"
#include <iostream>

using namespace std;
using namespace cv;

/*
*  Handles a frame of the webcam capture with face detection
*  Pre:		faces is a valid vector containing faces
*  Post:	frame is modifed
*/
void HatOverlayFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) {
	// Dont run if image not loaded
	if (!this->loaded) {
		return;
	}

	// For each face, overlay the hat
	for (size_t i = 0; i < faces.size(); i++) {
		Rect faceRect = faces[i].getFace();

		// The width of the face bounding box
		double destWidth = faceRect.width;
		// Original width of the hat image
		double origWidth = this->image.size().width;

		// Get the ratio of new to old widths
		double ratio = destWidth / origWidth;

		// Create the new size scaled by our ratio
		Size newSize((int)(origWidth * ratio), (int)(this->image.size().height * ratio));

		// Construct the new matrix to hold our scaled image
		Mat hat(newSize, true);
		// Self explainitory
		resize(this->image, hat, newSize);

		// The upper-left y-coordinate for our hat image
		int newY = (faceRect.y - newSize.height) + (int)(newSize.height * .3);
		// Do the overlay
		overlayImage(frame, hat, faceRect.x, newY);
	}
}

/*
*  Gets the name of this FrameHandler
*  Pre:		None
*  Post:	Returns the name of this FrameHandler
*/
string HatOverlayFrameHandler::getName() const {
	return "Hat";
}
