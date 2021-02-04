#pragma once

#include <unordered_map>

#include <bits/stdc++.h>

#include "Graph.h"
#include "Point.h"
#include "Edge.h"

using namespace std;

class Dijkstra {
	Graph graph;

	void FillResult(Point& src, unordered_map<int, bool>& mark, Point& target, unordered_map<int, Edge>& par);

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

	void UpdateGraph(Point src, Point dst, int val);
	void FindShortestPath(Point src, Point target);
};