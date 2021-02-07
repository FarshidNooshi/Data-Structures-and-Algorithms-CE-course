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

const int MAXN = 515;
const int px[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int py[] = {1, 0, -1, 1, -1, 0, 1, -1};
bool mark[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m;
char c[MAXN][MAXN];

void Solve();
void dfs(int, int);
bool valid(int, int);

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		cerr << "Program started.\n";
		int _ = 1;//	cin >> _;
		for (int __ = 1; __ <= _; __++)
		{
			Solve();
		}
	}
	
	return false;
}

void Solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	char st;	cin >> st;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == st)
				dfs(i, j);
	int ans = 0;
	pair<int, int> pos = {-1, -1};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == st && smax(ans, dp[i][j] + 1))
				pos = {i, j};
	cout << ans << '\n';
	cout << pos.first << ' ' << pos.second << '\n';
}

void dfs(int x, int y) {
	mark[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + px[i], ny = y + py[i];
		if (!valid(nx, ny))	continue;
		if (c[nx][ny] != char(c[x][y] + 1))	continue;
		if (!mark[nx][ny])
			dfs(nx, ny);
		smax(dp[x][y], dp[nx][ny] + 1);
	}
}

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}