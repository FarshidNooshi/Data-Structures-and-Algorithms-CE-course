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

	double CalculateDistance(Point target);
};