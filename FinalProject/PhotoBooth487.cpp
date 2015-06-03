/*
	PhotoBooth487
	Author: Dan Wager

	This is the main class that drives the application.
	It handles the loading of the webcam, loading of the FrameHandlers,
	and initializing the window for display.
*/

#include "PhotoBooth487.h"
#include "DummyFrameHandler.h"
#include "FaceBoxFrameHandler.h"
#include "FaceTextFrameHandler.h"
#include "HatOverlayFrameHandler.h"
#include "EdgyFrameHandler.h"
#include "LaplacianFilterFrameHandler.h"
#include "DrawFrameHandler.h"

#include "FPS.h"

#include <iostream>

using namespace std;
using namespace cv;

// The name of the window's title
const char *PhotoBooth487::WINDOW_NAME = "PhotoBooth 487";

/*
*  Constructor
*  Pre:		None
*  Post:	Photobooth is initialized
*/
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

/*
*  Initializes the webcam
*  Pre:		None
*  Post:	If it is initialized, loaded == true, else == false
*/
bool PhotoBooth487::initCamera(const int &camWidth, const int &camHeight) {
	this->camera = cvCreateCameraCapture(CV_CAP_ANY);
	cvSetCaptureProperty(this->camera, CV_CAP_PROP_FRAME_WIDTH, camWidth);
	cvSetCaptureProperty(this->camera, CV_CAP_PROP_FRAME_HEIGHT, camHeight);

	return this->camera != NULL;
}

/*
*  Initializes the window
*  Pre:		None
*  Post:	Window is named and initialized
*/
void PhotoBooth487::initWindow() {
	namedWindow(WINDOW_NAME, CV_WINDOW_NORMAL);
}

/*
*  Initializes the FrameHandlers
*  Pre:		None
*  Post:	frameHandlers is initialized
*/
void PhotoBooth487::initHandlers() {
	this->currentFrameHandler = new DummyFrameHandler;

	// Fill table of handlers
	this->frameHandlers[Keys::KEY_NUM_0] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_1] = new FaceBoxFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_2] = new FaceTextFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_3] = new HatOverlayFrameHandler("cap.png");
	this->frameHandlers[Keys::KEY_NUM_4] = new HatOverlayFrameHandler("top.png");
	this->frameHandlers[Keys::KEY_NUM_5] = new EdgyFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_6] = new LaplacianFilterFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_7] = new DrawFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_8] = currentFrameHandler;
	this->frameHandlers[Keys::KEY_NUM_9] = currentFrameHandler;
}

/*
*  Starts the frame grabbing and processing
*  Pre:		Webcam must be initialized
*  Post:	Frames are captured from the webcam and handled
*/
void PhotoBooth487::start() {
	if (!this->loaded) {
		cerr << "[ERROR] Camera not loaded! Can not start!" << endl;
		return;
	}

	// Set the mouse callback
	cvSetMouseCallback(WINDOW_NAME, onMouseEvent, this);

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

		// Actually get the frame from the webcam
		Mat frame = cvQueryFrame(this->camera);
		flip(frame, frame, 1);

		if (!frame.empty()) {
			currentFrameHandler->handleFrame(frame, keyPressed, WINDOW_NAME);

			// Put current frame handler in text
			putText(frame, currentFrameHandler->getName() + " Frame Handler", Point(10, frame.rows - 10), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(38, 121, 235), 1);
			// Redner the FPS
			putText(frame, "FPS: " + to_string(FPS::getAverageFPS()), Point(frame.cols - 100, frame.rows - 10), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(38, 121, 235), 1);
			// Actually show the frame on the window
			imshow(WINDOW_NAME, frame);
		}

		// We're done with that frame, release it!
		frame.release();
	}
}

/*
*  Callback for mouse events
*  Pre:		Must be registered with cvSetMouseCallback()
*  Post:	Calls onMouseEvent for current FrameHandler when selected
*/
void PhotoBooth487::onMouseEvent(int eventCode, int x, int y, int flags, void *param) {
	PhotoBooth487 *photoBooth = (PhotoBooth487*)param;
	photoBooth->currentFrameHandler->onMouseEvent(eventCode, x, y, flags);
}

/*
*  Destructor
*  Frees up webcam capture device if loaded
*/
PhotoBooth487::~PhotoBooth487() {
	if (this->loaded) {
		cvReleaseCapture(&this->camera);
	}
}
