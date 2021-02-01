#include "Headers\Analyser.h"
#include <unordered_map>

#include <bits/stdc++.h>

#include "Headers/Query.h"

using namespace std;

typedef long long ll;

void Analyser::solve() {
	//first := time of request. second->first := edge of request(src, dst), second->second := value of request.
	auto compare = [](pair<double, pair<Edge, int>> lhs, pair<double, pair<Edge, int>> rhs) {
		return lhs.first < rhs.first;
	};
	priority_queue<pair<double, pair<Edge, int>>, vector<pair<double, pair<Edge, int>>>, decltype(compare)> pq;

	while (!queries.empty()) {
		auto &item = queries.front();
		if (!pq.empty() && (-pq.top().first) < item.tme) {
			auto &it = pq.top();
			updateGraph(it.second.first.src, it.second.first.dst, it.second.second);
			pq.pop();
		}
		else {
			dijkstra.FindShortestPath(dijkstra.GetGraph().idToPoint[item.src], dijkstra.GetGraph().idToPoint[item.dst]);
		//	analysedMap[item] = Answer(dijkstra.timeRequiredForTraveling, dijkstra.result);
			double tme = item.tme;
			for (auto &edge : dijkstra.result) {
				pq.push({ -tme, {edge, 1} });
				{
					Edge temp = Edge(edge.src, edge.dst);
					temp.trafic = edge.trafic + 1;
					tme += temp.Weight();
					pq.push({ -tme, {temp, -1} });
				}
			}
			queries.pop();
		}
	}
}

void Analyser::updateGraph(Point src, Point dst, int val)
{
	auto graph = dijkstra.GetGraph();
	for (Edge& edge : graph.adj[src.id])
		if (edge.dst == dst) {
			edge.trafic += val;
			break;
		}
}
