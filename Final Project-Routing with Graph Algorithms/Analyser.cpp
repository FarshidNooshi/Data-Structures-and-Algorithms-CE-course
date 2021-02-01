#include <bits/stdc++.h>

#include "Headers/Analyser.h"
#include "Headers/Query.h"

using namespace std;

typedef long long ll;

void Analyser::solve(queue<Query> q) {
	//first := time of request. second->first := edge of request, second->second := value of request.
	priority_queue<pair<ll, pair<Edge, int>>, vector<pair<ll, pair<Edge, int>>>, less<pair<ll, pair<Edge, int>>>> pq;


}