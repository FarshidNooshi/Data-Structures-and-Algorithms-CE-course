#pragma once

#include "Graph.h"

using namespace std;

class Dijkstra {
	Graph graph;

	void FillResult(Point& src, unordered_map<int, bool>& mark, Point& target, unordered_map<int, int>& par);

public:

	vector<Edge> result;
	double timeRequiredForTraveling = 0.0;

	Graph GetGraph() { 
		return this->graph;
	}

	Dijkstra() = default;

	Dijkstra(Graph graph) {
		this->graph = graph;
	}

	void FindShortestPath(Point src, Point target);
};