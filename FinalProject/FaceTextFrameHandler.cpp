#include "FaceTextFrameHandler.h"
#include <iostream>

using namespace std;
using namespace cv;

FaceTextFrameHandler::FaceTextFrameHandler() {
	this->text = "";
}

void FaceTextFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<Face> faces, const char *windowName) {
	if (keyPressed == Keys::KEY_DELETE) {
		if (this->text.length() > 0) {
			this->text = this->text.substr(0, text.length() - 1);
		}
		return;
	}

	if (keyPressed != Keys::KEY_NONE) {
		if (keyPressed == Keys::KEY_SPACE ||
			keyPressed >= Keys::KEY_A_LOWER && keyPressed <= Keys::KEY_Z_LOWER ||
			keyPressed >= Keys::KEY_A_UPPER && keyPressed <= Keys::KEY_Z_UPPER) {
			this->text += (char)keyPressed;
		}
	}

	for (size_t i = 0; i < faces.size(); i++) {
		Rect face = faces[i].getFace();

		int baseline = 0;
		Size textSize = getTextSize(this->text, FONT_HERSHEY_COMPLEX_SMALL, 1.0, 3, &baseline);

		int xOffset = (face.x + textSize.width / 2) - (face.x + face.width / 2);
		Point newPoint(face.x - xOffset, face.y + 25);

		putText(frame, this->text, newPoint, FONT_HERSHEY_COMPLEX_SMALL, 1.0, Scalar(0, 0, 255), 3);
	}
}

string FaceTextFrameHandler::getName() const {
	return "Face Text";
}