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
#include <deque>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

typedef vector< vector<int> > Graph;

const int MAX_N = 250000;

int n;
int x,y;
Graph spanningTree(MAX_N);

//map < pair<int,int>, int > _dfs;
//vector < vector<int> > _dfs;
int _dfs[MAX_N][3];
int called = 0;
deque < tuple<int,int,int> > s;
int dfs(int p, int v, int availableEdges) {
	s.push_back( make_tuple(p,v,availableEdges) );
	called++;
	/*
	if (_dfs.count(make_pair(v, availableEdges))) {
		return _dfs[make_pair(v,availableEdges)];
	}
	*/
	if (_dfs[v][availableEdges] > 0) {
		//dout(v); dout(availableEdges);
		//s.pop_back();
		s.push_back(make_tuple(-1,-1,-1));
		return _dfs[v][availableEdges]-1;
	}
	if (_dfs[v][availableEdges] == -1) {
		for (auto si: s) {
			printf("-> %d %d %d\n",get<0>(si), get<1>(si), get<2>(si));
		}
		exit(1);
	}
	_dfs[v][availableEdges] = -1;
	int result = 0;
	int leftEdges = availableEdges;
	for (auto u: spanningTree[v]) {
		if (u != p) {
			int uv_taken = 1 + dfs(v, u, 1);
			int uv_untaken = dfs(v, u, 2);
			if (leftEdges &&  uv_taken > uv_untaken) {
				//take edge [v,u]
				result += uv_taken;
				leftEdges -= 1;
			} else {
				// don't take [v, u]
				result += uv_untaken;
			}
		}
	}
	//return _dfs[make_pair(v,availableEdges)] = result;

	_dfs[v][availableEdges] = result + 1;
	//printf("_dfs[%d][%d] = %d\n", v, availableEdges, result+1);
	//s.pop_back();
	//s.push_back(make_tuple(-1,-1,-1));
	return result;
}

int max_length_nonintersected_simple_paths() {
	//_dfs = vector< vector<int> > (n+1, vector<int>(3));
	memset(_dfs, 0, sizeof _dfs);
	return dfs(0, 1, 2);
}

void readData() {
	scanf("%d", &n);
	//spanningTree = Graph(n+1);
	scanf("%d%d", &x, &y);
	for (int i = 0; i < n-1; i++) {
		int u,v;
		scanf("%d%d", &u,&v);
		spanningTree[u].push_back(v);
		spanningTree[v].push_back(u);
	}
}

void solve() {
	int m = 0; // roads from spanningTree
	if (x >= y) {
		// use normal roads
		for (int i = 1; i <= n; i++)
			if (spanningTree[i].size() == n-1) m = 1;
	} else {
		m = max_length_nonintersected_simple_paths();
	}
	cout << (long long)m*x + (long long)(n-1-m)*y << "\n";
	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	solve();
	return 0;
}