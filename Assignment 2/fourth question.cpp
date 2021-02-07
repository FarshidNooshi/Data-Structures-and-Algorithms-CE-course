//In The Name Of GOD
#include <bits/stdc++.h>

using namespace std;

template <typename T, typename L>
bool smax(T &x, L y) { return x < y ? x = y, true : false; }

template <typename T, typename L>
bool smin(T &x, L y) { return x > y ? x = y, true : false; }

template <typename TType>
vector<TType> ReadLine()
{
	string s;
	getline(cin, s);
	stringstream stream(s);
	return vector<TType>((istream_iterator<TType>(stream)), (istream_iterator<TType>()));
}

typedef long long ll;

void solve();

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		cerr << "Program started.\n";
		int _ = 1; //	cin >> _;
		for (int __ = 1; __ <= _; __++)
		{
			solve();
		}
	}
	return false;
}

void solve()
{
	auto input = ReadLine<int>();
	vector<int> ans;
	int n = (int)input.size() / 2;
	for (int i = 0; i < n; i++) {
		ans.push_back(input[(int)input.size() - i - 1]);
		ans.push_back(input[i]);
	}
	if (((int)input.size()) & 1)
		ans.push_back(input[n]);
	for (auto item : ans)
		cout << item << ' ';
	cout << '\n';
}