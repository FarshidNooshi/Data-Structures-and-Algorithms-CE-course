//In The Name Of GOD
#include <bits/stdc++.h>

using namespace std;

template<typename T, typename L> bool smax(T& x, L y) { return x < y ? x = y, true : false; }
template<typename T, typename L> bool smin(T& x, L y) { return x > y ? x = y, true : false; }

typedef long long ll;

stack<pair<string, int>> st;

void solve();
vector<int> ReadUnclearInput();

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		int _ = 1;//	cin >> _;
		for (int __ = 1; __ <= _; __++) {
			solve();
		}
		
	}
	return false;
}

void solve() {
	int q;	cin >> q;
	while (q--) {
		int tme;
		string str;	cin >> str >> tme;
		if (str == "t") {
			while (tme >= 0) {
				if (st.empty()) {
					cout << "main\n";
					break;
				}
				auto item = st.top();
				st.pop();
				if (tme < item.second) {
					item.second -= tme;
					st.push(item);
					cout << item.first << '\n';
					break;
				}
				tme -= item.second;
			}
		} else {
			st.push({str, tme});
		}
	}

}