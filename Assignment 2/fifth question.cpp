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

struct Node {
	int value;
	Node *next;
	Node *prev;

	Node(int value) {
		next = NULL;
		prev = NULL;
		this->value = value;
	}
} *last, *middle;

int sz;

void Solve();
void Push(int );
void Pop();
void Print();
Node* FindMiddle();
void RemoveMiddle();
void Finish();

int32_t main()
{
	// ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	{
		cerr << "Program started.\n";
		int _ = 1; //	cin >> _;
		for (int __ = 1; __ <= _; __++)
		{
			Solve();
		}
	}
	return false;
}

void Solve()
{
	while (true) {
		string s;	cin >> s;
		if (s == "push") {
			int value;	cin >> value;
			Push(value);
		} else if (s == "pop")
			Pop();
		else if (s == "print")
			Print();
		else if (s == "findMiddle")
			cout << FindMiddle()->value << '\n';
		else if (s == "removeMiddle")
			RemoveMiddle();
		else if (s == "finish")
			Finish();
	}
	return;
}

void Push(int value) {
	if (!sz) {
		last = new Node(value);
		middle = new Node(value);
		sz++;
		return;
	}
	auto newNode = new Node(value);
	last->next = newNode;
	newNode->prev = last;
	last = newNode;
	if (sz == 1) {
		middle->next = newNode;
	}
	if (++sz & 1)
		middle = middle->next;
}

void Pop() {
	if (!sz) {
		return;
	} else if (sz == 1) {
		last = middle = NULL;
		sz = 0;
		return;
	} else if (sz == 2) {
	 	middle->next = NULL;
		last = new Node(middle->value);
		sz--;
		return;
	} else if (sz == 3) {
		middle->next = NULL;
	}
	last = last->prev;
	if (last != NULL)
		last->next = NULL;
	if (sz-- & 1)
		middle = middle->prev;
}

void Print() {
	auto it = &last;
	while ((*it) != NULL) {
		assert((*it)->value >= 0);
		cout << (*it)->value << ' ';
		it = &((*it)->prev);
	}
	cout << '\n';
}

Node* FindMiddle() {
	if (!sz) 
		return new Node(-1);
	return middle;
}

void RemoveMiddle() {
	if (!sz) { 
		return;
	} else if (sz == 1) {
		middle = last = NULL;
		sz = 0;
		return;
	} else if (sz == 2) {
		last->prev = NULL;
		middle = new Node(last->value);
		sz = 1;
		return;
	} else if (sz == 3) {
		last->prev = NULL;
	}
	auto prev = (middle->prev);
	auto nxt = (middle->next);
	middle->next->prev = prev;
	middle->prev->next = nxt;
	if (--sz & 1) 
		middle = nxt;
	else 
		middle = prev;
}

void Finish() {
	exit(0);
}