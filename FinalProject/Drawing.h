#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Drawing {
public:
	Drawing();
	~Drawing();

	cv::Rect &getDrawing();
private:
	cv::Rect drawing;
	cv::Point pivot;
};

