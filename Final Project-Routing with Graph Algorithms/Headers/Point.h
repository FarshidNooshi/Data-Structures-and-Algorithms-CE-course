#pragma once

class Point {
public:
	int id;
	double x;
	double y;

	Point(int id, double x, double y) {
		this->id = id;
		this->x = x;
		this->y = y;
	}

	bool operator==(const Point& point) const{
		return this->x == point.x &&
			this->y == point.y;
	}

	Point() =  default;

	double CalculateDistance(Point target);
};