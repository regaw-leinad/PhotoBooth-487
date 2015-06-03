/*
	Face
	Author: Dan Wager

	This class encapsulates the data that represents a detected face
	in a frame.
*/

#pragma once

#include "opencv2/objdetect/objdetect.hpp"

class Face {
public:
	Face(cv::Rect &face);
	~Face() {}

	/*
	*  Gets the Rect that bounds the face
	*  Pre:		None
	*  Post:	Returns the face Rect
	*/
	cv::Rect getFace() const;

private:
	// The face Rect
	cv::Rect face;
};
