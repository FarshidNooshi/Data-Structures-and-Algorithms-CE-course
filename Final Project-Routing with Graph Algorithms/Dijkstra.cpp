#include "Headers\Dijkstra.h"

#include <unordered_map>

#include <bits/stdc++.h>

#include "Headers/Dijkstra.h"
#include "Headers/Point.h"
#include "Headers/Edge.h"

using namespace std;

template <typename T, typename L>
bool smax(T& x, L y) { return x < y ? x = y, true : false; }

template <typename T, typename L>
bool smin(T& x, L y) { return x > y ? x = y, true : false; }

void Dijkstra::FindShortestPath(Point src, Point target) {
	unordered_map<int, bool> mark;
	unordered_map<int, double> dis;
	unordered_map<int, Edge> par;
	priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;

	dis[src.id] = 0;
	pq.push({ 0, src.id });
	
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (mark[v])
			continue;
		mark[v] = true;
		for (auto& edge : graph.adj[v]) {
			if (smin(dis[edge.dst.id], dis[v] + edge.Weight())) {
				par[edge.dst.id] = edge;
				pq.push({ dis[edge.dst.id], edge.dst.id });
			}
		}
	}

	timeRequiredForTraveling = dis[target.id] * 120.0;
	FillResult(src, mark, target, par);
}

void Dijkstra::FillResult(Point& src, unordered_map<int, bool>& mark, Point& target, unordered_map<int, Edge>& par)
{
	if (!mark[target.id]) {
		throw "no root from requested nodes.";
	}

	result.clear();

	int f = target.id;
	Edge edge = par[f];
	while (f != src.id) {
		edge = par[f];
		f = edge.src;
		result.push_back(edge);
	}
	reverse(result.begin(), result.end());
}
