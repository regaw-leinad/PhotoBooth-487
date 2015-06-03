/*
	ImageOverlayFrameHandler
	Author: Dan Wager

	This class allows you to overlay an image on top of a face
	To extend this class, you must implement handleFaceDetectionFrame() and getName().
*/

#pragma once

#include "FaceDetectionFrameHandler.h"

class ImageOverlayFrameHandler : public FaceDetectionFrameHandler {
public:
	// The tolerance for the green screen pixel values
	static const int GREEN_SCREEN_PIXEL_TOLERANCE = 80;

	ImageOverlayFrameHandler(const std::string &imageFilePath);
	~ImageOverlayFrameHandler();

	/*
	*  Overlays an image on top of another
	*  Pre:		None
	*  Post:	overlay is overlaid on top of frame at the coordinates (x, y)
	*/
	void overlayImage(cv::Mat &frame, const cv::Mat &overlay, int startX, int startY) const;

	/*
	*  Determines if a pixel is part of the "green screen"
	*  Pre:		None
	*  Post:	True if the pixel is part of the green screen, false otherwise
	*/
	bool isGreenScreenPixel(const cv::Vec3b &pixel) const;

protected:
	// The image to overlay
	cv::Mat image;
	bool loaded;
};

