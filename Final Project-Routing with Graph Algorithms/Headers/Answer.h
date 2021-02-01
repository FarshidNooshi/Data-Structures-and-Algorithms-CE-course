#pragma once

#include "Edge.h"

using namespace std;

class Answer {
public:
	int timeElapsed;
	vector<Edge> path;

	Answer(int tme, vector<Edge> vec) {
		timeElapsed = tme;
		path = vec;
	}
};