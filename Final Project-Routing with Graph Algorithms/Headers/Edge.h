#pragma once

#include "Point.h"

class Edge {
public:
	int trafic;
	double length;
	static const double traficFactor;

	double Weight();

	Edge(double length) {
		this->length = length;
		trafic = 0;
	}

	Edge(Point src, Point target) {
		this->length = src.CalculateDistance(target);
		trafic = 0;
	}

};