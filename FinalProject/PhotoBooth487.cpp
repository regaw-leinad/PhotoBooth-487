#include "PhotoBooth487.h"

#include <iostream>

using namespace std;
using namespace cv;

PhotoBooth487::PhotoBooth487(const int &camWidth, const int &camHeight) {
	this->loaded = false;

	if (!initCamera(camWidth, camHeight)) {
		cerr << "[ERROR] Webcam not loaded successfully" << endl;
		return;
	}

	initWindow();

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

void PhotoBooth487::start() {
	if (!this->loaded) {
		cerr << "[ERROR] Camera not loaded! Can not start!" << endl;
		return;
	}
}

PhotoBooth487::~PhotoBooth487() {
	if (this->loaded) {
		cvReleaseCapture(&this->camera);
	}
}
