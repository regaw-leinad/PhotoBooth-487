#include "Face.h"

using namespace cv;

Face::Face(Rect &face) {
	this->face = face;
}

Rect Face::getFace() const {
	return this->face;
}
