#pragma once

#include "FaceDetectionFrameHandler.h"

class FaceTextFrameHandler : public FaceDetectionFrameHandler {
public:
	FaceTextFrameHandler();
	~FaceTextFrameHandler() {}

	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<cv::Rect> faces, const char *windowName);

	std::string getName() const;

private:
	std::string text;
};

