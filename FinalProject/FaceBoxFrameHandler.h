#pragma once

#include "FaceDetectionFrameHandler.h"

class FaceBoxFrameHandler : public FaceDetectionFrameHandler {
public:
	FaceBoxFrameHandler() {}
	~FaceBoxFrameHandler() {}

	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<Face> faces, const char *windowName);
	void onMouseEvent(int eventCode, int x, int y, int flags);

	std::string getName() const;
};

