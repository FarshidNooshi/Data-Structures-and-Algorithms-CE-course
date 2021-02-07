//In The Name Of GOD
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

using namespace std;

// #define int long long
#define infll 4557430888798830399
#define infInt 1061109567

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

struct Edge {
	int to, price, id;
	Edge(int id, int v, int pr) {
		this->id = id;
		to = v;
		price = pr;
	}
};

const int MAXN = 60;
int n, src, dst, l;
int dist[MAXN][MAXN];
int par[MAXN][MAXN];
vector<Edge> adj[MAXN];
bool mark[MAXN][MAXN];

void Solve();
void dfs(int , int);

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
	memset(dist, 63, sizeof(dist));
	cin >> n;
	for (int i = 0, u, v, pr; i < n; i++) {
		cin >> u >> v >> pr;
		adj[u].push_back({i, v, pr});
	}
	cin >> src >> dst >> l;
	dist[src][0] = 0;
	par[src][0] = src;
	dfs(src, 0);
	if (dist[dst][l] == infInt) {
		cout << "Impossible\n";
		return;
	}
	vector<int> vec;
	{
		int v = dst, level = l;
		while (v != src) {
			vec.push_back(v);
			v = par[v][level--];
		}
		vec.push_back(src);
		reverse(vec.begin(), vec.end());
	}
	for (auto u : vec)
		cout << u << ' ';
	cout << dist[dst][l] << '\n'; 
}

void dfs(int v, int level) {
	for (auto u : adj[v]) {
		if (smin(dist[u.to][level + 1], dist[v][level] + u.price)) {
			par[u.to][level + 1] = v;
		}		
		dfs(u.to, level + 1);
	}
}