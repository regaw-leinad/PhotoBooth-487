#pragma once

#include "FaceDetectionFrameHandler.h"

class FaceBoxFrameHandler : public FaceDetectionFrameHandler {
public:
	FaceBoxFrameHandler() {}
	~FaceBoxFrameHandler() {}

	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<Face> faces, const char *windowName);

	std::string getName() const;
};

