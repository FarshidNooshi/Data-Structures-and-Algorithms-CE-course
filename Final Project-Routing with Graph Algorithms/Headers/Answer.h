#pragma once

#include <bits/stdc++.h>

#include "Edge.h"

using namespace std;

class Answer {
public:
	double timeElapsed;
	vector<Edge> path;

	Answer() = default;

	Answer(double tme, vector<Edge> vec) {
		timeElapsed = tme;
		path = vec;
	}
};