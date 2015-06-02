#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class PhotoBooth487 {
public:
	const char *WINDOW_NAME = "PhotoBooth487";

	PhotoBooth487(const int &camWidth, const int &camHeight);
	~PhotoBooth487();

	void start();

private:
	CvCapture *camera;
	bool loaded;

	bool initCamera(const int &camWidth, const int &camHeight);
	void initWindow();
};

