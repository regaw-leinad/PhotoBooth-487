/*
Drawing
Author: Dan Wager

Represents a drawing on a frame that pivots aroud a point.
*/

#include "Drawing.h"

using namespace cv;

/*
*  Copy constructor
*/
Drawing::Drawing(const Drawing &d) {
	this->points = vector<Point>(d.points);
	this->pivot = Point(d.pivot);
}

/*
*  Gets the points that make up the drawing
*  Pre:		None
*  Post:	Returns a reference to the collection of Points
*/
const vector<Point>& Drawing::getDrawing() const {
	return this->points;
}

/*
*  Adds a point to the drawing
*  Pre:		None
*  Post:	the new point is added to the collection
*/
void Drawing::addPoint(const Point &point) {
	this->points.push_back(point);
}

/*
*  Sets the pivot point
*  Pre:		None
*  Post:	Sets the pivot point to the point specified
*/
void Drawing::setPivot(const cv::Point &pivot) {
	this->pivot = pivot;
}

/*
*  Gets the pivot point lol
*  Pre:		None
*  Post:	Returns the pivot point
*/
const Point &Drawing::getPivot() const {
	return this->pivot;
}

/*
*  Clears the drawing
*  Pre:		None
*  Post:	The drawing has no points and is cleared
*/
void Drawing::clear() {
	this->points.clear();
}
