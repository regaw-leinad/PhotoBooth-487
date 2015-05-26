#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

const int KEY_ESCAPE = 27;
const int KEY_NONE = -1;
const int KEY_DELETE = 8;

const string window_name = "Capture - Face detection";
const string face_cascade_name = "lbpcascade_frontalface.xml";
const string eyes_cascade_name = "haarcascade_eye.xml";
const string mouth_cascade_name = "haarcascade_mcs_mouth.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string text = "";
Mat hat;

void rotate(Mat& src, Mat& dst, double angle) {
	int len = max(src.cols, src.rows);
	Point2f pt(len / 2., len / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);

	warpAffine(src, dst, r, Size(len, len));
}

/** @function detectAndDisplay */
void detectAndDisplay(Mat frame) {
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	/*std::vector<Rect> eyes;
	eyes_cascade.detectMultiScale(frame_gray, eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	for (size_t j = 0; j < eyes.size(); j++) {
		Point center(eyes[j].x + eyes[j].width * 0.5, eyes[j].y + eyes[j].height * 0.5);
		int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
		circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
	}

	imshow(window_name, frame);*/

	//-- Detect faces
	/*for (int times = 0; times < 3; times++) {
		double angle = -45 + times * 45;
		rotate(frame_gray, frame_gray, angle);*/
		
		face_cascade.detectMultiScale(frame_gray, faces, 1.1, 5, 0 | CV_HAAR_SCALE_IMAGE, Size(50, 50));
		if (faces.size() > 0) {
			for (unsigned int i = 0; i < faces.size(); i++) {
				Rect face = faces[i];
				//Point center(face.x + face.width * 0.5, face.y + face.height * 0.5);
				putText(frame, text, Point(face.x, face.y + 25), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 0, 255), 3);
				//hat.copyTo(frame);
				//rectangle(frame, face, Scalar(0, 255, 0), 4);
				//Mat faceROI = frame_gray(face);
				/*Mat faceEdge = frame(face);
				Canny(faceEdge, faceEdge, 20, 60);
				faceEdge.copyTo(faceROI);*/

				
				/*std::vector<Rect> eyes;

				eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

				for (size_t j = 0; j < eyes.size(); j++) {
					Point center(face.x + eyes[j].x + eyes[j].width * 0.5, face.y + eyes[j].y + eyes[j].height * 0.5);
					int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
					circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
				}*/
			}

		/*	break;*/
	}

	//-- Show what you got
	imshow(window_name, frame);
}

int main(int argc, char *argv[]) {
	CvCapture* capture;

	if (!face_cascade.load(face_cascade_name)) {
		cerr << "Error loading " << face_cascade_name << endl;
		return -1;
	};

	if (!eyes_cascade.load(eyes_cascade_name)) {
		cerr << "Error loading " << eyes_cascade_name << endl;
		return -1;
	};

	hat = imread("cap.png", -1);

	capture = cvCaptureFromCAM(CV_CAP_ANY);

	if (capture) {
		while (true) {
			Mat frame = cvQueryFrame(capture);
			flip(frame, frame, 1);

			if (!frame.empty()) {
				detectAndDisplay(frame);
			}

			int key = waitKey(1);
			if (key == KEY_ESCAPE) {
				break; 
			} else if (key != KEY_NONE) {
				if (key == KEY_DELETE) {
					text = text.substr(0, text.length() - 1);
				} else {
					text += (char)key;
				}
			}
		}
	}

	return 0;
}

