#pragma once

#include "opencv2/objdetect/objdetect.hpp"

class Face {
public:
	Face(cv::Rect &face);
	~Face() {}

	cv::Rect getFace() const;

private:
	cv::Rect face;
};

