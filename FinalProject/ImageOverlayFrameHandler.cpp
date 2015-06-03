#include "ImageOverlayFrameHandler.h"
#include <iostream>

using namespace std;
using namespace cv;

ImageOverlayFrameHandler::ImageOverlayFrameHandler(const string &imageFilePath) {
	this->image = imread(imageFilePath, CV_LOAD_IMAGE_COLOR);

	if (!this->image.data) {
		this->loaded = false;
		cerr << "[ERROR] Can not load image: " << imageFilePath << endl;
		return;
	}

	this->loaded = true;
}

ImageOverlayFrameHandler::~ImageOverlayFrameHandler() {
	this->image.release();
}

void ImageOverlayFrameHandler::overlayImage(cv::Mat &frame, const cv::Mat &hat, int startX, int startY) const {
	int width = hat.size().width;
	int height = hat.size().height;

	for (int x = startX; x < startX + width; x++) {
		if (x < 0) {
			continue;
		}

		if (x >= frame.size().width - 1) {
			break;
		}

		for (int y = startY; y < startY + height; y++) {
			if (y < 0) {
				continue;
			}

			if (y >= frame.size().height - 1) {
				break;
			}

			Vec3b hatVal = hat.at<Vec3b>(y - startY, x - startX);
			// skip if green screen
			if (!isGreenScreenPixel(hatVal)) {
				frame.at<Vec3b>(y, x) = hatVal;
			}
		}
	}
}

bool ImageOverlayFrameHandler::isGreenScreenPixel(const Vec3b &pixel) const {
	return pixel[0] <= GREEN_SCREEN_PIXEL_TOLERANCE &&
		std::abs(pixel[1] - 255) <= GREEN_SCREEN_PIXEL_TOLERANCE &&
		pixel[2] <= GREEN_SCREEN_PIXEL_TOLERANCE;
}
