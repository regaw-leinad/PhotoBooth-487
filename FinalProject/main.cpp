#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "PhotoBooth487.h"

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
const int CAMERA_WIDTH = 800;
const int CAMERA_HEIGHT = 600;

unordered_map<int, FrameHandler*> frameHandlers;
FrameHandler *currentFrameHandler;

int currentMode = 0;

void onMouseEvent(int event, int x, int y, int flags, void* userdata) {
}

int main(int argc, char *argv[]) {
	PhotoBooth487 photoBooth(CAMERA_WIDTH, CAMERA_HEIGHT);
	// Init to dummy frame handler (does nothing)
	currentFrameHandler = new DummyFrameHandler;

	// Fill table of handlers
	frameHandlers[Keys::KEY_NUM_0] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_1] = new FaceBoxFrameHandler;
	frameHandlers[Keys::KEY_NUM_2] = new FaceTextFrameHandler;
	frameHandlers[Keys::KEY_NUM_3] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_4] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_5] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_6] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_7] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_8] = currentFrameHandler;
	frameHandlers[Keys::KEY_NUM_9] = currentFrameHandler;

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

	return 0;
}

