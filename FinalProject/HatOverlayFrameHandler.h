/*
	HatOverlayFrameHandler
	Author: Dan Wager

	Detects a face and puts a hat on their head!
	Extends ImageOverlayFrameHandler to provide the image.
*/

#pragma once

#include "ImageOverlayFrameHandler.h"

class HatOverlayFrameHandler : public ImageOverlayFrameHandler {
public:
	HatOverlayFrameHandler(const std::string &hatFilePath) : ImageOverlayFrameHandler(hatFilePath) {}
	~HatOverlayFrameHandler() {}

	/*
	*  Handles a frame of the webcam capture with face detection
	*  Pre:		faces is a valid vector containing faces
	*  Post:	frame is modifed
	*/
	void handleFaceDetectionFrame(cv::Mat &frame, const int &keyPressed, const std::vector<Face> &faces, const char *windowName);
	
	/*
	*  Gets the name of this FrameHandler
	*  Pre:		None
	*  Post:	Returns the name of this FrameHandler
	*/
	std::string getName() const;
};

