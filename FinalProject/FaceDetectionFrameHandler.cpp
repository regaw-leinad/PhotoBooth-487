#include "FaceDetectionFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

FaceDetectionFrameHandler::FaceDetectionFrameHandler() {
	if (!this->faceCascade.load(FACE_CASCADE_NAME)) {
		cerr << "Error loading " << FACE_CASCADE_NAME << " for FaceDetectionFrameHandler" << endl;
		this->loaded = false;
		return;
	}

	this->loaded = true;
}

void FaceDetectionFrameHandler::handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName) {
	if (this->loaded) {
		// Do face detection
		vector<Rect> faces;
		Mat frameGrey;

		cvtColor(frame, frameGrey, CV_BGR2GRAY);
		equalizeHist(frameGrey, frameGrey);

		this->faceCascade.detectMultiScale(frameGrey, faces, 1.1f, 6, 0 | CV_HAAR_SCALE_IMAGE, Size(50, 50));

		handleFaceDetectionFrame(frame, keyPressed, faces, windowName);
	}
}

