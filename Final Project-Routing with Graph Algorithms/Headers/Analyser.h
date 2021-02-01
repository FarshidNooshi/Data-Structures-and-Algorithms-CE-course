#pragma once

#include "Dijkstra.h"
#include "Graph.h"

struct Query {
    int src;
    int dst;
    int tme;

    Query(int tme, int src, int dst) {
        this->src = src;
        this->dst = dst;
        this->tme = tme;
    }
};

class Analyser {
	Dijkstra dijkstra;

public:
	Analyser(Graph graph) {
		dijkstra = Dijkstra(graph);
	}

	void solve(queue<Query> q);
};