#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Keys.h"
#include "DummyFrameHandler.h"
#include "FaceBoxFrameHandler.h"
#include "FaceTextFrameHandler.h"

#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;
using namespace cv;

const char *windowName = "CSS487 PhotoBooth";

unordered_map<int, FrameHandler*> frameHandlers;
FrameHandler *currentFrameHandler;

int currentMode = 0;

void rotate(Mat& src, Mat& dst, double angle) {
	int len = max(src.cols, src.rows);
	Point2f pt(len / 2., len / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);

	warpAffine(src, dst, r, Size(len, len));
}

/** @function detectAndDisplay */
/*void detectAndDisplay(Mat frame) {
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	std::vector<Rect> eyes;
	eyes_cascade.detectMultiScale(frame_gray, eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	for (size_t j = 0; j < eyes.size(); j++) {
		Point center(eyes[j].x + eyes[j].width * 0.5, eyes[j].y + eyes[j].height * 0.5);
		int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
		circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
	}

	imshow(window_name, frame);

	//-- Detect faces
	for (int times = 0; times < 3; times++) {
		double angle = -45 + times * 45;
		rotate(frame_gray, frame_gray, angle);
		
		face_cascade.detectMultiScale(frame_gray, faces, 1.1, 6, 0 | CV_HAAR_SCALE_IMAGE, Size(50, 50));
		if (faces.size() > 0) {
			for (unsigned int i = 0; i < faces.size(); i++) {
				Rect face = faces[i];
				//Point center(face.x + face.width * 0.5, face.y + face.height * 0.5);
				putText(frame, text, Point(face.x, face.y + 25), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 0, 255), 3);
				//hat.copyTo(frame);
				rectangle(frame, face, Scalar(0, 255, 0), 4);
				//Mat faceROI = frame_gray(face);
				Mat faceEdge = frame(face);
				Canny(faceEdge, faceEdge, 20, 60);
				faceEdge.copyTo(faceROI);

				
				std::vector<Rect> eyes;

				eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

				for (size_t j = 0; j < eyes.size(); j++) {
					Point center(face.x + eyes[j].x + eyes[j].width * 0.5, face.y + eyes[j].y + eyes[j].height * 0.5);
					int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
					circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
				}
			}

			break;
	}

	//-- Show what you got
	imshow(windowName, frame);
}*/

void onMouseEvent(int event, int x, int y, int flags, void* userdata) {
}

int main(int argc, char *argv[]) {
	CvCapture* capture;

	// Create camera
	capture = cvCreateCameraCapture(CV_CAP_ANY);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 800);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 600);

	if (capture) {
		// Create the window
		namedWindow(windowName, CV_WINDOW_NORMAL);

		// Init to dummy frame handler (does nothing)
		currentFrameHandler = new DummyFrameHandler;

		// Fill table of handlers
		frameHandlers[Keys::KEY_NUM_0] = currentFrameHandler;
		frameHandlers[Keys::KEY_NUM_1] = new FaceBoxFrameHandler;
		frameHandlers[Keys::KEY_NUM_2] = new FaceTextFrameHandler;
		frameHandlers[Keys::KEY_NUM_3] = currentFrameHandler;
		frameHandlers[Keys::KEY_NUM_4] = currentFrameHandler;
		frameHandlers[Keys::KEY_NUM_5] = currentFrameHandler;

		// Main frame loop
		while (true) {
			// Get key press
			int keyPressed = waitKey(1);

			if (keyPressed == Keys::KEY_ESCAPE) {
				// Exit on ESCAPE
				break;
			}
			
			if (keyPressed != Keys::KEY_NONE) {
				// O(1) lookup and set for new FrameHandler
				FrameHandler *newHandler = frameHandlers[keyPressed];

				if (newHandler != NULL) {
					keyPressed = Keys::KEY_NONE;
					currentFrameHandler = newHandler;
				}
			}

			Mat frame = cvQueryFrame(capture);
			flip(frame, frame, 1);

			if (!frame.empty()) {
				currentFrameHandler->handleFrame(frame, keyPressed, windowName);
				// Put current frame handler in text
				putText(frame, currentFrameHandler->getName() + " Frame Handler", Point(10, frame.rows - 10), FONT_HERSHEY_COMPLEX, 0.5, Scalar(127, 0, 0), 2);
				imshow(windowName, frame);
			}
		}

		cvReleaseCapture(&capture);
	}

	return 0;
}

