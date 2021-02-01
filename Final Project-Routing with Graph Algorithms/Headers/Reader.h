#pragma once

#include "Point.h"
#include "Analyser.h"
#include "Query.h"

using namespace std;

class Reader {
public:
	vector<Point> points;
	vector<pair<int, int>> edgeIds;
	queue<Query> queries;
	
	Reader() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	}


	int numberOfPoints = 0;
	int numberOfEdges = 0;

	void ReadMap();
	
	void ReadQueries();
};