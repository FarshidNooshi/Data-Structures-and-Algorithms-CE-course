#pragma once

#include "Dijkstra.h"
#include "Graph.h"
#include "Query.h"

class Analyser {
	Dijkstra dijkstra;

public:
	Analyser(Graph graph) {
		dijkstra = Dijkstra(graph);
	}

	void solve(queue<Query> q);
};