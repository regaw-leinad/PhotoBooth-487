#pragma once

#include "FrameHandler.h"

class FaceDetectionFrameHandler : public FrameHandler {
	const std::string FACE_CASCADE_NAME = "lbpcascade_frontalface.xml";

public:
	FaceDetectionFrameHandler();
	~FaceDetectionFrameHandler() {}

	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);
	virtual void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<cv::Rect> faces, const char *windowName) = 0;

private:
	bool loaded;
	cv::CascadeClassifier faceCascade;
};

