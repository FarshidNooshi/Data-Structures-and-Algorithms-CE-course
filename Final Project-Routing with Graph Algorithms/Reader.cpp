#include <bits/stdc++.h>

#include "Headers/Reader.h"

using namespace std;

void Reader::ReadMap() {
	cin >> numberOfPoints >> numberOfEdges;
	for (int i = 0, id, x, y; i < numberOfPoints; i++) {
		cin >> id >> x >> y;
		points.push_back({ id, x, y });
	}

	for (int i = 0, idSource, idTarget; i < numberOfEdges; i++) {
		cin >> idSource >> idTarget;
		edgeIds.push_back({ idSource, idTarget });
	}
}

void Reader::ReadQueries() {
	int tme, src, dst;
	vector<Query> vec;
	while (cin >> tme >> src >> dst) {
		vec.push_back({ tme, src, dst });
	}

	sort(vec.begin(), vec.end());
	for (auto& item : vec)
		queries.push(item);
}