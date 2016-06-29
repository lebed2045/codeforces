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

const int MAX_N = 401;
int n, m;
vector< vector<int> > railway(MAX_N), road(MAX_N);
vector< vector<bool> > isRailway(MAX_N, vector<bool>(MAX_N, false));

int bfs(vector< vector<int> > g) {
	vector<int> d(MAX_N, -1);
	d[1] = 0;
	queue<int> q({1}); 
	while (!q.empty()) {
		int curr_vertex = q.front(); q.pop();
		for (int next_vertex : g[curr_vertex]) 
			if (d[next_vertex] == -1){
				d[next_vertex] = d[curr_vertex] + 1;
				q.push(next_vertex);
			}
	}
	return d[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		railway[u].push_back(v);
		railway[v].push_back(u);
		isRailway[u][v] = isRailway[v][u] = true;
	}

	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++)
			if (!isRailway[u][v]) {
				road[u].push_back(v);
				road[v].push_back(u);
			}
	}

	int time_by_train = bfs(railway);
	int time_by_bus = bfs(road);

	if (time_by_bus == -1 || time_by_train == -1) {
		cout << "-1" << endl;
	} else {
		cout << max(time_by_train, time_by_bus) << endl;
	}

	return 0;
}