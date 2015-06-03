/*
	Keys
	Author: Dan Wager

	This is the main class that drives the application.
	It handles the loading of the webcam, loading of the FrameHandlers,
	and initializing the window for display.
*/

#pragma once

#include "Keys.h"
#include "FrameHandler.h"

#include <unordered_map>

class PhotoBooth487 {
public:
	// The name of the window's title
	static const char *WINDOW_NAME;

	PhotoBooth487(const int &camWidth, const int &camHeight);
	~PhotoBooth487();

	/*
	*  Starts the frame grabbing and processing
	*  Pre:		Webcam must be initialized
	*  Post:	Frames are captured from the webcam and handled
	*/
	void start();

private:
	// The actual webcam capture
	CvCapture *camera;
	// If the webcam is loaded
	bool loaded;
	// The map of FrameHandlers to choose from
	std::unordered_map<int, FrameHandler*> frameHandlers;
	// The current FrameHandler being used
	FrameHandler *currentFrameHandler;

	/*
	*  Initializes the webcam
	*  Pre:		None
	*  Post:	If it is initialized, loaded == true, else == false
	*/
	bool initCamera(const int &camWidth, const int &camHeight);

	/*
	*  Initializes the window
	*  Pre:		None
	*  Post:	Window is named and initialized
	*/
	void initWindow();

	/*
	*  Initializes the FrameHandlers
	*  Pre:		None
	*  Post:	frameHandlers is initialized
	*/
	void initHandlers();

	/*
	*  Callback for mouse events
	*  Pre:		Must be registered with cvSetMouseCallback()
	*  Post:	Calls onMouseEvent for current FrameHandler when selected
	*/
	static void onMouseEvent(int eventCode, int x, int y, int flags, void *param);
};

