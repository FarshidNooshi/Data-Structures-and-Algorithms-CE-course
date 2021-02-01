#pragma once

#include <unordered_map>

#include "Point.h"
#include "Edge.h"

using namespace std;

class Graph {
public:
	unordered_map<int, Point> idToPoint;
	unordered_map<int, vector<Edge>> adj;

	int numberOfPoints = 0;
	int numberOfEdges = 0;

	Graph() = default;

	Graph(vector<Point> points, vector<pair<int, int>> edges) {

		numberOfPoints = points.size();
		numberOfEdges = edges.size();

		for (auto& point : points)
			idToPoint[point.id] = point;

		for (int i = 0; i < edges.size(); i++) {
			adj[edges[i].first].push_back({ idToPoint[edges[i].first], idToPoint[edges[i].second] });
			adj[edges[i].second].push_back({ idToPoint[edges[i].second], idToPoint[edges[i].first] });
		}
	}
};