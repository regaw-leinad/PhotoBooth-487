/*
	FaceBoxFrameHandler
	Author: Dan Wager

	This class draws a rectangle around a detected face.
	It extends from FaceDetectionFrameHandler for the facial detection.
*/

#pragma once

#include "FaceDetectionFrameHandler.h"

class FaceBoxFrameHandler : public FaceDetectionFrameHandler {
public:
	FaceBoxFrameHandler() {}
	~FaceBoxFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture with face detection
	*  Pre:		faces is a valid vector containing faces
	*  Post:	a rectangle is drawn around all the detected faces
	*/
	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName);

	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const;
};
