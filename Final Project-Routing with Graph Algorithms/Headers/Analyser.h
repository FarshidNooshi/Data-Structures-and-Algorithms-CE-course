#pragma once

#include "Dijkstra.h"
#include "Graph.h"
#include "Query.h"
#include "Answer.h"

using namespace std;

class Analyser {
	Dijkstra dijkstra;

public:

	map<Query, Answer> analysedMap;

	Analyser(Graph graph) {

		dijkstra = Dijkstra(graph);
	}

	void solve(queue<Query> q);
	void updateGraph(Point src, Point dst, int val);
};