#pragma once
#include "Point.h"

using namespace std;

class Reader {
public:
	Reader() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	}

	vector<Point> points;
	vector<pair<int, int>> edgeIds;

	int numberOfPoints = 0;
	int numberOfEdges = 0;

	void ReadMap();
};