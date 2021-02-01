#include "Headers\Analyser.h"
#include <unordered_map>

#include <bits/stdc++.h>

#include "Headers/Query.h"

typedef pair<double, pair<Edge, int>> priorityItem;

using namespace std;

typedef long long ll;

void Analyser::solve(queue<Query> q) {
	//first := time of request. second->first := edge of request(src, dst), second->second := value of request.
	priority_queue<priorityItem, vector<priorityItem, less<priorityItem>>> pq;

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
			double tme = item.tme;
			for (auto edge : dijkstra.result) {
				pq.push({ tme, {edge, 1} });
				{
					Edge temp = Edge(edge.src, edge.dst);
					temp.trafic = edge.trafic + 1;
					tme += temp.Weight();
					pq.push({ tme, {temp, -1} });
				}
			}
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
