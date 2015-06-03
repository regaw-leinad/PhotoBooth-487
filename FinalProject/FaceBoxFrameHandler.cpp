#include "FaceBoxFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

void FaceBoxFrameHandler::handleFaceDetectionFrame(Mat &frame, const int &keyPressed, vector<Face> faces, const char *windowName) {
	for (size_t i = 0; i < faces.size(); i++) {
		Face face = faces[i];

		rectangle(frame, face.getFace(), Scalar(0, 255, 0), 4);
	}
}

void FaceBoxFrameHandler::onMouseEvent(int eventCode, int x, int y, int flags) {
	cout << "FaceBoxFrameHandler Mouse Event" << endl;
}

string FaceBoxFrameHandler::getName() const {
	return "Face Box";
}
