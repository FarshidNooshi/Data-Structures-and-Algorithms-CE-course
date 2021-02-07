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

const int MAXN = 120;
int n;
vector<int> ans;
int a[MAXN];

void Solve();

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
	cin >> n;
	for (int i = 2; i <= n; i++)
		cin >> a[i];
	ans.push_back(n);
	int p = n;
	while (p != 1) {
		ans.push_back(a[p]);
		p = a[p];
	}
	reverse(ans.begin(), ans.end());
	for (auto u : ans)
		cout << u << ' ';
	cout << '\n';
}
