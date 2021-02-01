#include "Headers\Analyser.h"
#include <bits/stdc++.h>

#include "Headers/Analyser.h"
#include "Headers/Query.h"

using namespace std;

typedef long long ll;

void Analyser::solve(queue<Query> q) {
	//first := time of request. second->first := edge of request, second->second := value of request.
	priority_queue<pair<ll, pair<Edge, int>>, vector<pair<ll, pair<Edge, int>>>, less<pair<ll, pair<Edge, int>>>> pq;

	while (!q.empty()) {
		auto item = q.front();
		if (!pq.empty() && pq.top().first < item.tme) {
			auto it = pq.top();
			pq.pop();
			updateGraph(it.second.first.src, it.second.first.dst, it.second.second);
		}
		else {
			q.pop();
			dijkstra.FindShortestPath(item.src, item.dst);
			analysedMap[item] = { dijkstra.timeRequiredForTraveling, dijkstra.result };
		}

	}
}

void Analyser::updateGraph(Point src, Point dst, int val)
{
	auto& graph = dijkstra.GetGraph();
	for (Edge& edge : graph.adj[src])
		if (edge.dst == dst) {
			edge.trafic += val;
			break;
		}
}
