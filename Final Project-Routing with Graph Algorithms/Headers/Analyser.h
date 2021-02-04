#pragma once

#include <unordered_map>

#include <bits/stdc++.h>

#include "Dijkstra.h"
#include "Graph.h"
#include "Query.h"
#include "Answer.h"
#include "Point.h"

using namespace std;

class Analyser {
	Dijkstra dijkstra;
	queue<Query> queries;

public:

	map<Query, Answer> analysedMap;

	Analyser() = default;

	Analyser(Graph graph, queue<Query> queries) {
		this->queries = queries;
		dijkstra = Dijkstra(graph);
	}

	void solve();
};