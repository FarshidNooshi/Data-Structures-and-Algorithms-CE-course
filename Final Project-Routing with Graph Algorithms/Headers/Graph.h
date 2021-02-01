#pragma once

#include <unordered_map>

#include "Point.h"
#include "Edge.h"

using namespace std;

class Graph {
public:
	unordered_map<int, Point> idToPoint;
	unordered_map<int, vector<Edge>> adj;
	Graph(vector<Point> points, vector<pair<int, int>> edges) {

		for (auto& point : points)
			idToPoint[point.id] = point;

		for (int i = 0; i < edges.size(); i++) {
			adj[edges[i].first].push_back({ idToPoint[edges[i].first], idToPoint[edges[i].second] });
		}
	}
};