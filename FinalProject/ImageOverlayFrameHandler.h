#pragma once

#include "FaceDetectionFrameHandler.h"

class ImageOverlayFrameHandler : public FaceDetectionFrameHandler {
public:
	static const int GREEN_SCREEN_PIXEL_TOLERANCE = 80;

	ImageOverlayFrameHandler(const std::string &imageFilePath);
	~ImageOverlayFrameHandler();

	void overlayImage(cv::Mat &frame, const cv::Mat &overlay, int startX, int startY) const;
	bool isGreenScreenPixel(const cv::Vec3b &pixel) const;

protected:
	cv::Mat image;
	bool loaded;
};

