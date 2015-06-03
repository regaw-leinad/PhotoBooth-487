#pragma once

#include "ImageOverlayFrameHandler.h"

class HatOverlayFrameHandler : public ImageOverlayFrameHandler {
public:
	static const int GREEN_SCREEN_PIXEL_TOLERANCE = 80;

	HatOverlayFrameHandler(const std::string &hatFilePath) : ImageOverlayFrameHandler(hatFilePath) {}
	~HatOverlayFrameHandler() {}

	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, std::vector<Face> faces, const char *windowName);
	
	std::string getName() const;
};

