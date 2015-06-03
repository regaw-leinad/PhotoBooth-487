/*
	Drawing
	Author: Dan Wager

	Represents a drawing on a frame that pivots aroud a point.
*/

#pragma once

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Drawing {
public:
	Drawing() {}
	Drawing(const Drawing &d);
	~Drawing() {}

	/*
	*  Gets the points that make up the drawing
	*  Pre:		None
	*  Post:	Returns a reference to the collection of Points
	*/
	const std::vector<cv::Point> &getDrawing() const;
	
	/*
	*  Adds a point to the drawing
	*  Pre:		None
	*  Post:	the new point is added to the collection
	*/
	void addPoint(const cv::Point &point);

	/*
	*  Sets the pivot point
	*  Pre:		None
	*  Post:	Sets the pivot point to the point specified
	*/
	void setPivot(const cv::Point &pivot);

	/*
	*  Gets the pivot point lol
	*  Pre:		None
	*  Post:	Returns the pivot point
	*/
	const cv::Point &getPivot() const;

	/*
	*  Clears the drawing
	*  Pre:		None
	*  Post:	The drawing has no points and is cleared
	*/
	void clear();
private:
	std::vector<cv::Point> points;
	cv::Point pivot;
};

