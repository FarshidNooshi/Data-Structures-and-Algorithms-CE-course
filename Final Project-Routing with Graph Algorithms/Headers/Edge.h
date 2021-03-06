#pragma once

#include <bits/stdc++.h>

#include "Point.h"

class Edge {
public:
	Point src;
	Point dst;
	int trafic;
	double length;
	static const double traficFactor;

	Edge() = default;

	double Weight();

	Edge(Point src, Point target) {
		this->src = src;
		this->dst = target;
		this->length = src.CalculateDistance(target);
		trafic = 0;
	}

};