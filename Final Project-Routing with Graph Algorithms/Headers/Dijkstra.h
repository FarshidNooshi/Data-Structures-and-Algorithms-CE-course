#pragma once

#include "Headers/Graph.h"

using namespace std;

class Dijkstra {
	Graph graph;

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
	void FillResult(unordered_map<int, bool>& mark, Point& target, unordered_map<int, int>& par);
};