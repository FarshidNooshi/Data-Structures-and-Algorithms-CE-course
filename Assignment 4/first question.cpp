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

const int MAXN = 1000;
const int px[] = {1, -1, 0, 0};
const int py[] = {0, 0, 1, -1};
int dist[MAXN][MAXN];
char s[MAXN][MAXN];
queue<pair<int, int>> q;
int n, m;

void init();
void Solve();
bool valid(int, int);
void bfs();

int32_t main()
{
	// ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		// cerr << "Program started.\n";
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
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	init();

	bfs();

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			dist[i][j] = (dist[i][j] == 1000000 ? -1 : dist[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	
			cout << dist[i][j] << ' ';
		cout << '\n';
	}
}

void init() {
	for (int i = 0; i < MAXN; i++)
		fill(dist[i], dist[i] + MAXN, 1000 * 1000);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'M') {
				q.push({i, j});
				dist[i][j] = 0;
			}
}

void bfs() {
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		int x = v.first, y = v.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + px[i], ny = y + py[i];
			if (valid(nx, ny)) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != 'X' && dist[x][y] == 1000000;
}