#include "Util.h"

using namespace cv;

/*
	Ratates an image by the specified number of degrees
*/
void Util::rotateImage(const cv::Mat &source, cv::Mat &destination, const double &angle) {
	int len = std::max(source.cols, source.rows);
	Point2f pt(len / 2., len / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);

	warpAffine(source, destination, r, Size(len, len));
}
