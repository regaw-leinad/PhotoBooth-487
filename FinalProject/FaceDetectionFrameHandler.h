/*
	FaceDetectionFrameHandler
	Author: Dan Wager

	This is the base class for all classes that want to handle and modify a frame
	of the webcam capture based on face detection.
	To extend this class, you must implement handleFaceDetectionFrame() and getName()
*/

#pragma once

#include "FrameHandler.h"
#include "Face.h"

class FaceDetectionFrameHandler : public FrameHandler {
	// The name of the cascade xml file to use for face detection
	const std::string FACE_CASCADE_NAME = "lbpcascade_frontalface.xml";

public:
	FaceDetectionFrameHandler();
	~FaceDetectionFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture
	*  Pre:		None
	*  Post:	frame is modifed
	*/
	void handleFrame(cv::Mat &frame, const int &keyPressed, const char *windowName);

	/*
	*  Handles a frame of the webcam capture with face detection
	*  Pre:		faces is a valid vector containing faces
	*  Post:	frame is modifed
	*/
	virtual void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName) = 0;

private:
	// If the cascade is loaded
	bool loaded;
	// The face detectoin cascade
	cv::CascadeClassifier faceCascade;
};
