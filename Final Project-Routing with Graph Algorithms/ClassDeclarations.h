#pragma once

class Edge {
public: 
	int trafic;
	double length;
	static const double traficFactor = 0.3;

	double Weight() {
		return length * (1.0 + trafic * traficFactor);
	}

	Edge(double length) {
		this->length = length;
		trafic = 0;
	}

};

class Point {
public:
	int id;
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	double CalculateDistance(Point target) {
		int dx = this->x - target.x;
		int dy = this->y - target.y;
		return sqrt(dx * dx + dy * dy);
	}
};