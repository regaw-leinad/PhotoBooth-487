/*
	Face
	Author: Dan Wager

	This class encapsulates the data that represents a detected face
	in a frame.
*/

#include "Face.h"

using namespace cv;

Face::Face(Rect &face) {
	this->face = face;
}

/*
*  Gets the Rect that bounds the face
*  Pre:		None
*  Post:	Returns the face Rect
*/
Rect Face::getFace() const {
	return this->face;
}
