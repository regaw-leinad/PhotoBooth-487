/*
	Main
	Author: Dan Wager

	Main entry point for the PhotoBooth application
*/

#include "PhotoBooth487.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *args[]) {
	// 1st arg is executable path and name
	if (argc != 3) {
		cerr << "[ERROR] Invalid argument count" << endl;
		cerr << "Usage: PhotoBooth.exe <cameraWidth> <cameraHeight>" << endl;
		return -1;
	}

	// Use the height and width from the command line
	int cameraWidth = atoi(args[1]);
	int cameraHeight = atoi(args[2]);

	// Validate width and height
	if (cameraWidth == 0) {
		cerr << "[ERROR] Invalid cameraWidth: " << args[1] << endl;
		return -1;
	}

	if (cameraHeight == 0) {
		cerr << "[ERROR] Invalid cameraHeight: " << args[2] << endl;
		return -1;
	}

	// Init photo booth and start
	PhotoBooth487 photoBooth(cameraWidth, cameraHeight);
	photoBooth.start();

	return 0;
}
