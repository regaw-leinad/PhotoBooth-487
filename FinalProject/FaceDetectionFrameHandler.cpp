/*
	FaceDetectionFrameHandler
	Author: Dan Wager

	This is the base class for all classes that want to handle and modify a frame
	of the webcam capture based on face detection.
	To extend this class, you must implement handleFaceDetectionFrame() and getName()
*/

#include "FaceDetectionFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;


FaceDetectionFrameHandler::FaceDetectionFrameHandler() {
	// Load the haar cascase for facial detection
	if (!this->faceCascade.load(FACE_CASCADE_NAME)) {
		cerr << "Error loading " << FACE_CASCADE_NAME << " for FaceDetectionFrameHandler" << endl;
		this->loaded = false;
		return;
	}

	this->loaded = true;
}

/*
*  Handles a frame of the webcam capture
*  Pre:		None
*  Post:	frame is modifed
*/
void FaceDetectionFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	if (this->loaded) {
		// Do face detection
		vector<Rect> faceRects;
		
		Mat frameGrey;

		cvtColor(frame, frameGrey, CV_BGR2GRAY);
		equalizeHist(frameGrey, frameGrey);

		// Do the actual face detection
		this->faceCascade.detectMultiScale(frameGrey, faceRects, 1.1f, 6, 0 | CV_HAAR_SCALE_IMAGE, Size(50, 50));

		vector<Face> faces;

		// Add all faces to the collection
		for (size_t i = 0; i < faceRects.size(); i++) {
			faces.push_back(Face(faceRects[i]));
			// Add eye detection here if necessary
		}

		// Call the virtual face detection handler method
		handleFaceDetectionFrame(frame, keyPressed, faces, windowName);
	}
}

