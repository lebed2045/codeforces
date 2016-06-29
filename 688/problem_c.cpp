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
//#define FORN(i,n) for (int i = 0; i < (int)n; i++) BS
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};

const int MAX_N = 1e5+7;

vi v;
queue<int> q;
priority_queue<int, std::vector<int>, std::greater<int> > pq;
string s;

int n,m,k;

vector<vi> g(MAX_N);
vi c(MAX_N, -1);

bool paint(int v,int color) {
	if (c[v] != -1) return c[v] != color;
	c[v] = color;
	for (auto u: g[v]) {
		if (paint(u,color^1)) return true;
	}
	return false;
}

vi A, B;
void solve() {
	bool answer = false;
	for (int v = 1; v <= n; v++) {
		if (c[v] == -1) {
			answer |= paint(v,0);
		}
	}
	if (answer) {
		printf("-1\n");
	} else {
		for (int v = 1; v <= n; v++) {
			if (c[v] == 0) A.pb(v); else B.pb(v);
		}
		printf("%d\n", (int)A.size());
		for (auto v: A) {
			printf("%d ", v); 
		}
		printf("\n");
		printf("%d\n", (int)B.size());
		for (auto v: B) {
			printf("%d ", v); 
		}
		printf("\n");
	}
}

void readData() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u,v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
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