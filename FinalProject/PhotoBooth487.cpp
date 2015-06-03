#include "PhotoBooth487.h"
#include "DummyFrameHandler.h"
#include "FaceBoxFrameHandler.h"
#include "FaceTextFrameHandler.h"

#include <iostream>

using namespace std;
using namespace cv;

const char *PhotoBooth487::WINDOW_NAME = "PhotoBooth487";

PhotoBooth487::PhotoBooth487(const int &camWidth, const int &camHeight) {
	this->loaded = false;

	cout << "Initializing capture device..." << endl;
	if (!initCamera(camWidth, camHeight)) {
		cerr << "[ERROR] Webcam not loaded successfully" << endl;
		return;
	}

	cout << "Initializing display window..." << endl;
	initWindow();
	cout << "Initializing Frame Handlers..." << endl;
	initHandlers();
	cout << "PhotoBooth487 loaded successfully" << endl;

	this->loaded = true;
}

bool PhotoBooth487::initCamera(const int &camWidth, const int &camHeight) {
	this->camera = cvCreateCameraCapture(CV_CAP_ANY);
	cvSetCaptureProperty(this->camera, CV_CAP_PROP_FRAME_WIDTH, camWidth);
	cvSetCaptureProperty(this->camera, CV_CAP_PROP_FRAME_HEIGHT, camHeight);

	return this->camera;
}

void PhotoBooth487::initWindow() {
	namedWindow(WINDOW_NAME, CV_WINDOW_NORMAL);
}

void PhotoBooth487::initHandlers() {
	this->currentFrameHandler = new DummyFrameHandler;

	// Fill table of handlers
	this->frameHandlers[Keys::KEY_NUM_0] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_1] = new FaceBoxFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_2] = new FaceTextFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_3] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_4] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_5] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_6] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_7] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_8] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_9] = currentFrameHandler;
}

void PhotoBooth487::start() {
	if (!this->loaded) {
		cerr << "[ERROR] Camera not loaded! Can not start!" << endl;
		return;
	}

	cvSetMouseCallback(WINDOW_NAME, onMouseEvent, NULL);

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

		Mat frame = cvQueryFrame(this->camera);
		flip(frame, frame, 1);

		if (!frame.empty()) {
			currentFrameHandler->handleFrame(frame, keyPressed, WINDOW_NAME);

			// Put current frame handler in text
			putText(frame, currentFrameHandler->getName() + " Frame Handler", Point(10, frame.rows - 10), FONT_HERSHEY_COMPLEX, 0.5, Scalar(127, 0, 0), 2);
			imshow(WINDOW_NAME, frame);
		}
	}
}

void PhotoBooth487::onMouseEvent(int eventCode, int x, int y, int flags, void *param) {
	cout << "Mouse event" << endl;
}

PhotoBooth487::~PhotoBooth487() {
	if (this->loaded) {
		cvReleaseCapture(&this->camera);
	}
}
