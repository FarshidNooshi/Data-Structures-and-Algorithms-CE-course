#include "Headers\Dijkstra.h"

#include <unordered_map>

#include <bits/stdc++.h>

#include "Headers/Dijkstra.h"
#include "Headers/Point.h"

using namespace std;

template <typename T, typename L>
bool smax(T& x, L y) { return x < y ? x = y, true : false; }

template <typename T, typename L>
bool smin(T& x, L y) { return x > y ? x = y, true : false; }


typedef long long ll;

void Dijkstra::FindShortestPath(Point src, Point target) {
	unordered_map<int, bool> mark;
	unordered_map<int, int> dis, par;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, less<pair<ll, int>>> pq;

	dis[src.id] = 0;
	par[src.id] = -1;
	pq.push({ 0, src.id });
	
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (mark[v])
			continue;
		mark[v] = true;
		for (auto& edge : graph.adj[v]) {
			if (smin(dis[edge.dst.id], dis[v] + edge.Weight())) {
				par[edge.dst.id] = v;
				pq.push({ dis[edge.dst.id], edge.dst.id });
			}
		}
	}

	timeRequiredForTraveling = dis[target.id] * 120.0;
	FillResult(mark, target, par);
}

void Dijkstra::FillResult(unordered_map<int, bool>& mark, Point& target, unordered_map<int, int>& par)
{
	if (!mark[target.id]) {
		throw "no root from requested nodes.";
	}

	int f = target.id;
	while (f != -1) {
		result.push_back(f);
		f = par[f];
	}
	reverse(result.begin(), result.end());
}
