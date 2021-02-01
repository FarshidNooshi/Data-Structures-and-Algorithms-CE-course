#pragma once

class Point {
public:
	int id;
	int x;
	int y;

	Point(int id, int x, int y) {
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