#pragma once

#include "Point.h"

using namespace std;

class Answer {
public:
	int timeElapsed;
	vector<Point> path;

	Answer(int tme, vector<Point> vec) {
		timeElapsed = tme;
		path = vec;
	}
};