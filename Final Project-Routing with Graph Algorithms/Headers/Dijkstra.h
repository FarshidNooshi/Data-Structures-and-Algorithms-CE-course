#pragma once

#include "Headers/Graph.h"

using namespace std;

class Dijkstra {
	Graph graph;

public:

	vector<Edge> result;

	Graph GetGraph() { 
		return this->graph;
	}

	Dijkstra(Graph graph) {
		this->graph = graph;
	}

	void FindShortestPath(Point src, Point target);
};