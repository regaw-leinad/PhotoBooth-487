#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Util {
public:
	static void rotateImage(const cv::Mat &source, cv::Mat &destination, const double &angle);
};

