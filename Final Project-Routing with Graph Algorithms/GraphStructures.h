#pragma once

class Edge {
public: 
	int trafic;
	double length;
	static const double traficFactor;

	double Weight() {
		return length * (1.0 + trafic * traficFactor);
	}

	Edge(double length) {
		this->length = length;
		trafic = 0;
	}

	Edge(Point src, Point target) {
		this->length = src.CalculateDistance(target);
		trafic = 0;
	}

};

const double Edge::traficFactor = 0.3;

class Point {
public:
	int id;
	int x;
	int y;

	Point(int id, int x, int y) {
		this->id = id;
		this->x = x;
		this->y = y;
	}

	double CalculateDistance(Point target) {
		int dx = this->x - target.x;
		int dy = this->y - target.y;
		return sqrt(dx * dx + dy * dy);
	}
};

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