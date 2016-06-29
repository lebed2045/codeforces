#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#include <string>
#include <vector>
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

const int MAX_N = 500+5;
int n, m;
vector < vector<bool> > a(MAX_N, vector<bool>(MAX_N, false) );
string s;

vector <bool> was(MAX_N, false);
bool dfs(int v) {
	was[v] = true;
	for (int u = 0; u < n; u++) {
		if (v != u && !a[v][u]) {
			if (!was[u]) {
				if (s[v] == 'b') 
					s[v] = 'a';
				s[u] = (s[v] == 'a' ? 'c' : 'a');
				if (dfs(u) == false)
					return false;
			} else {
				if ( abs(s[u] - s[v]) <= 1 ) 
					return false;
			}
		}
	}
	return true;
}

bool solution() {
	for (int i = 0; i < n; i++) {
		//dout (s);
		if (!was[i] && dfs(i) == false) return false;
	}
	// check
	for (int v = 0; v < n; v++) 
		for (int u = v+1; u < n; u++) {
			if (a[u][v] && abs(s[v] - s[u]) > 1) return false;
			if (!a[u][v] && abs(s[v] - s[u]) <= 1) return false;
		}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	
	scanf("%d%d", &n, &m);
	s = string(n, 'b');
	for (int i = 0; i < m; i++) {
		int u,v;
		scanf("%d%d", &u,&v);
		u--;
		v--;
		a[u][v] = a[v][u] = true;
	}
	
	if (solution()) {
		cout << "Yes\n";
		cout << s;
	} else {
		cout << "No\n";
	}
	return 0;
}