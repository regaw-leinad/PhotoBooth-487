

#include "HatOverlayFrameHandler.h"
#include <iostream>

using namespace cv;
using namespace std;

void HatOverlayFrameHandler::handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) {
	if (!this->loaded) {
		return;
	}

	for (size_t i = 0; i < faces.size(); i++) {
		Rect faceRect = faces[i].getFace();

		double destWidth = faceRect.width;
		double origWidth = this->image.size().width;

		double ratio = destWidth / origWidth;

		Size newSize((int)(origWidth * ratio), (int)(this->image.size().height * ratio));

		Mat hat(newSize, true);
		resize(this->image, hat, newSize);

		int newY = (faceRect.y - newSize.height) + (int)(newSize.height * .3);
		overlayImage(frame, hat, faceRect.x, newY);
	}
}

string HatOverlayFrameHandler::getName() const {
	return "Hat";
}
