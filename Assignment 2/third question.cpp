//In The Name Of GOD
#include <bits/stdc++.h>

using namespace std;

template <typename T, typename L> bool smax(T &x, L y) { return x < y ? x = y, true : false; }
template <typename T, typename L> bool smin(T &x, L y) { return x > y ? x = y, true : false; }

typedef long long ll;

const int MAXN = 1e4 + 15;
int n, k, h, t;
vector<int> blackValue[MAXN], redValue;
int iterated[MAXN];

void solve();

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		cerr << "Program started.\n";
		int _ = 1; //	cin >> _;
		for (int __ = 1; __ <= _; __++) {
			solve();
		}
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0, inp; j < k; j++) {
			cin >> inp;
			blackValue[i].push_back(inp);
		}
	cin >> h;
	for (int i = 0, inp; i < h; i++) {
		cin >> inp;
		redValue.push_back(inp);
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int value = redValue[i % h];
		int blackNumber = i % n;
		int& iterateValue = iterated[blackNumber];
		iterateValue += value;
		iterateValue = ((iterateValue % k) + k) % k;
	}
	for (int i = (t % n); i < n; i++)
		cout << blackValue[i][iterated[i]];
	for (int i = 0; i < (t % n); i++)
		cout << blackValue[i][iterated[i]];
	cout << '\n';
	return;
}