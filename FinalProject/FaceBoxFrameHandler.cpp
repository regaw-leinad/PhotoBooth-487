#include "FaceBoxFrameHandler.h"

using namespace std;
using namespace cv;

void FaceBoxFrameHandler::handleFaceDetectionFrame(Mat &frame, const int &keyPressed, vector<Face> faces, const char *windowName) {
	for (size_t i = 0; i < faces.size(); i++) {
		Face face = faces[i];

		rectangle(frame, face.getFace(), Scalar(0, 255, 0), 4);
	}
}

string FaceBoxFrameHandler::getName() const {
	return "Face Box";
}
