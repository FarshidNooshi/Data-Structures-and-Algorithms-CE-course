//In The Name Of GOD
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

using namespace std;

// #define int long long

template <typename T, typename L>
bool smax(T &x, L y) { return x < y ? x = y, true : false; }

template <typename T, typename L>
bool smin(T &x, L y) { return x > y ? x = y, true : false; }

// template<typename T> 
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


template <typename TType>
vector<TType> ReadLine()
{
	string s;
	getline(cin, s);
	stringstream stream(s);
	return vector<TType>((istream_iterator<TType>(stream)), (istream_iterator<TType>()));
}

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ull;

const int MAXN = 5015;
unordered_map<int, map<int, bool>> mp[4];// 0 -> north, 1 -> east, 2 -> south, 3 -> west

void Solve();
void updateAns(int& , int, int, int);

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		cerr << "Program started.\n";
		int _ = 1;	cin >> _;
		for (int __ = 1; __ <= _; __++)
		{
			Solve();
		}
	}
	
	return false;
}

void Solve()
{
	for (int j = 0; j < 4; j++)
		mp[j].clear();
	string s;	cin >> s;
	int ans = 0;
	int x = 0, y = 0;
	for (auto u : s) {
		int v = 0;
		if (u == 'E') {
			v = 1;
			updateAns(ans, v, x, y);
			mp[3][++x][y] = true;
		} else if (u == 'S') {
			v = 2;
			updateAns(ans, v, x, y);
			mp[0][x][--y] = true;
		} else if (u == 'W') {
			v = 3;
			updateAns(ans, v, x, y);
			mp[1][--x][y] = true;
		} else {
			v = 0;
			updateAns(ans, v, x, y);
			mp[2][x][++y] = true;
		}
	}
	cout << ans << '\n';
}

void updateAns(int& ans, int v, int x, int y) {
	if (mp[v][x][y])
		ans += 1;
	else 
		ans += 5;
	mp[v][x][y] = true;
}
