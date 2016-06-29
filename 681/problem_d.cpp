#include <cstdio>
#include <cstring>
#define M_PI 3.14159265359
#include <cmath>
#include <cassert>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

#define ALL(x) (x).begin(), (x).end()
#define FORN(i,n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};

queue<int> q;
priority_queue<int, std::vector<int>, std::greater<int> > pq;

const int MAX_N = 1e5+7;
int n,m;
vi answer;
vi a;
vector <vi> child(MAX_N);
vector <bool> root(MAX_N, true);
vector <bool> inList(MAX_N, false);
vector <bool> visited(MAX_N, false);

vi st;
bool noAnswer = false;

void dfs(int v) {
	visited[v] = true;
	if (inList[v]) {
		//dout(i);
		st.pb(v);
		answer.pb(v);
	}
	if (a[v] != st[ st.size()-1 ]) {
		/*dout(i);
		dout(st[ st.size()-1 ]);
		dout(a[i]);*/
		noAnswer = true;
		return;
	}
	for (auto ch: child[v]) {
		if (!visited[ch]) {
			dfs(ch);
		}
	}
	st.pop_back();	
}

void solve() {
	for(int i = 1; i <= n; i++) {
		if (root[i] && !visited[i]) { //root
			if (a[i] != i) {
				while(1) {};
			}
			st.clear();
			dfs(i);
		}
	}
	if (noAnswer) {
		printf("-1\n");
	} else {
		printf("%d\n", (int)answer.size());
		for (int i = answer.size(); i > 0; --i) {
			printf("%d\n", answer[i-1]);
		}
	}
}

void readData() {
	scanf("%d%d", &n, &m);
	FORN(i,m) {
		int p,q;
		scanf("%d%d", &p, &q);
		child[p].pb(q);
		root[q] = false;
	}
	a.pb(-1);
	FORN(i,n) {
		int ai;
		scanf("%d", &ai);
		a.pb(ai);
		inList[ai] = true;
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	solve();
	return 0;
}