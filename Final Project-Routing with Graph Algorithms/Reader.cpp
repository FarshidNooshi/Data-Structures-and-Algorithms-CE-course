#include <bits/stdc++.h>

#include "Headers/Reader.h"

using namespace std;

void Reader::ReadMap() {
	cin >> numberOfPoints >> numberOfEdges;
	for (int i = 0, id; i < numberOfPoints; i++) {
		double x, y;
		cin >> id >> x >> y;
		points.push_back({ id, x, y });
	}

	for (int i = 0, idSource, idTarget; i < numberOfEdges; i++) {
		cin >> idSource >> idTarget;
		edgeIds.push_back({ idSource, idTarget });
	}
}

void Reader::ReadQueries() {
	double tme;
	int src, dst;
	vector<Query> vec;
	cout << "enter number of queries:\n";

	/*while (cin >> tme >> src >> dst) {
		vec.push_back({ tme, src, dst });
	}*/

	{
		int temp;	cin >> temp;
		while (temp--) {
			cin >> tme >> src >> dst;
			vec.push_back({ tme, src, dst });
		}
	}

	sort(vec.begin(), vec.end(), [](Query& left, Query& right) {
		return left.tme < right.tme;
		});
	for (auto& item : vec)
		queries.push(item);
}