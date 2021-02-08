#include <bits/stdc++.h>

#include "Headers/Point.h"

double Point::CalculateDistance(Point target) {
	double dx = this->x - target.x;
	double dy = this->y - target.y;
	return sqrt(dx * dx + dy * dy);
}
