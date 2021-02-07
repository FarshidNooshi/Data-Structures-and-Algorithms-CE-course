//In The Name Of GOD
#include <bits/stdc++.h>

using namespace std;

template<typename T, typename L> bool smax(T& x, L y) { return x < y ? x = y, true : false; }
template<typename T, typename L> bool smin(T& x, L y) { return x > y ? x = y, true : false; }

typedef long long ll;

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

vector<int> ReadUnclearInput() {
	string s;	
	getline(cin, s);
	stringstream stream(s);
	return vector<int>((istream_iterator<int>(stream)), (istream_iterator<int>()));
}

void solve() {
	vector<int> input = ReadUnclearInput();
	stack<int> stack;
	set<int> st;
	int pt = 0;
	for (int i = 1; i <= (int)input.size(); i++) {
		if (!stack.empty() && stack.top() == i) {
			stack.pop();
			st.erase(i);
			continue;
		} else if (st.count(i)) {
			cout << "no\n";
			return;
		}
		while (pt < (int)input.size()) {
			if (input[pt] == i) {
				pt++;
				break;
			}
			st.insert(input[pt]);
			stack.push(input[pt++]);
		}
	}
	cout << "yes\n";
	return;
}