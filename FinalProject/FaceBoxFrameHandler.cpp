#include "FaceBoxFrameHandler.h"

using namespace std;
using namespace cv;

void FaceBoxFrameHandler::handleFaceDetectionFrame(Mat &frame, const int &keyPressed, vector<Face> faces, const char *windowName) {
	for (size_t i = 0; i < faces.size(); i++) {
		Face face = faces[i];

		rectangle(frame, face.getFace(), Scalar(0, 255, 0), 4);

		for (size_t j = 0; j < faces[i].getEyes().size(); j++) {
			Rect eye = faces[i].getEyes()[j];

			Point center(face.getFace().x + eye.x + eye.width * 0.5, face.getFace().y + eye.y + eye.height * 0.5);
			int radius = cvRound((eye.width + eye.height) * 0.25);

			circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
	}
}

string FaceBoxFrameHandler::getName() const {
	return "Face Box";
}
