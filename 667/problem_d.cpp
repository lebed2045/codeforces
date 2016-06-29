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

#define ALL(x) (x).begin(),(x).end()
#define dout(x) cerr << #x << " = " << x << endl;

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

const int MAX_N = 3000 + 7;
int n, m;
vector < vector<int> > g(MAX_N);
vector < vector<int> > d(MAX_N, vector<int>(MAX_N, -1));
vector < vector<int> > topFurtherFrom(MAX_N);
vector < vector<int> > topFurtherTo(MAX_N);

void bfs(int s) {
	queue <int> q;
	d[s][s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto &to: g[v]) {
			if (d[s][to] == -1) {
				d[s][to] = d[s][v] + 1;
				q.push(to);
			}
		}
	}
}

void calcTopFurther() {
	//from 
	vector < pair<int,int> > temp;
	for (int from = 1; from <= n; from++) {
		temp.clear();
		for (int to = 1; to <= n; to++) {
			temp.push_back( make_pair( d[from][to], to ) );
		}
		sort( temp.rbegin(), temp.rend() );
		for (int i = 0; i < 3; i++) {
			topFurtherFrom[from].push_back( temp[i].second );
		}
	}
	//to
	for (int to = 1; to <= n; to++) {
		temp.clear();
		for (int from = 1; from <= n; from++) {
			temp.push_back( make_pair(d[from][to], from) );
		}
		sort( temp.rbegin(), temp.rend() );
		for (int i = 0; i < 3; i++) {
			topFurtherTo[to].push_back( temp[i].second );
		}
	}
}

void solve() {
	for (int v = 1; v <= n; v++) {
		bfs(v);
	}
	calcTopFurther();
	// find w, x, y, z
	int answer_d = 0;
	int answer_w = -1, answer_x = -1, answer_y = -1, answer_z = -1;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) 
			if (y != x && d[x][y] >= 0) {
			for (int w: topFurtherTo[x]) 
				if (w != x && w != y && d[w][x] >= 0) {
				for (int z: topFurtherFrom[y]) 
					if (z != w && z != x && z != y && d[y][z] >= 0) {
						int curr_d = d[w][x] + d[x][y] + d[y][z];
						//printf("%d %d %d %d, = %d = (%d + %d + %d)\n", w,x,y,z, curr_d, d[w][x], d[x][y], d[y][z]);
						
						if (curr_d > answer_d) {
							answer_d = curr_d;
							answer_w = w;
							answer_x = x;
							answer_y = y;
							answer_z = z;
						}
					}
				}
			}
	}
	//dout(answer_d);
	printf("%d %d %d %d\n", answer_w, answer_x, answer_y, answer_z);
}

void readData() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
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