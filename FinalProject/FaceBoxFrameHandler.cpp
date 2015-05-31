#include "FaceBoxFrameHandler.h"

using namespace std;
using namespace cv;

void FaceBoxFrameHandler::handleFaceDetectionFrame(Mat &frame, const int &keyPressed, vector<Rect> faces, const char *windowName) {
	for (size_t i = 0; i < faces.size(); i++) {
		rectangle(frame, faces[i], Scalar(0, 255, 0), 4);
	}
}

string FaceBoxFrameHandler::getName() const {
	return "Face Box";
}
