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