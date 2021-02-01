#pragma once

#include <bits/stdc++.h>

#include "Edge.h"

using namespace std;

class Answer {
public:
	int timeElapsed;
	vector<Edge> path;

	Answer() = default;

	Answer(int tme, vector<Edge> vec) {
		timeElapsed = tme;
		path = vec;
	}
};