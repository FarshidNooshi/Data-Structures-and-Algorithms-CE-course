#pragma once

#include "Graph.h"

using namespace std;

class Dijkstra {
	Graph graph;

	void FillResult(unordered_map<int, bool>& mark, Point& target, unordered_map<int, int>& par);

public:

	vector<Point> result;
	double timeRequiredForTraveling;

	Graph GetGraph() { 
		return this->graph;
	}

	Dijkstra() = default;

	Dijkstra(Graph graph) {
		this->graph = graph;
	}

	void FindShortestPath(Point src, Point target);
};