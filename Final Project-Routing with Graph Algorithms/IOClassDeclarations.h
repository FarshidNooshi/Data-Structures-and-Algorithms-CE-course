#pragma once

class Reader {
public:
	Reader() {
		ios_base::sync_with_stdio(false), cin.tie(false), cout.tie(false);
	}

	vector<Point> points;
	vector<pair<int, int>> edgeIds;

	int numberOfPoints;
	int numberOfEdges;

	void ReadMap() {
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
};