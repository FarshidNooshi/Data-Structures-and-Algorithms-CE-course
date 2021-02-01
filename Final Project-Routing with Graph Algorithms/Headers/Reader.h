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
	
	Reader() = default;


	int numberOfPoints = 0;
	int numberOfEdges = 0;

	void ReadMap();
	
	void ReadQueries();
};