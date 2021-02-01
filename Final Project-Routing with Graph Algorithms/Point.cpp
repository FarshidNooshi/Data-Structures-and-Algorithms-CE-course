#include <bits/stdc++.h>

#include "Headers/Point.h"

double Point::CalculateDistance(Point target) {
	int dx = this->x - target.x;
	int dy = this->y - target.y;
	return sqrt(dx * dx + dy * dy);
}
