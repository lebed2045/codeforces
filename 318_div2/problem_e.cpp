#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int MAX_N = 200000 + 9;
int n;
pair<int,int> e[MAX_N];
vector<int> g[MAX_N]; 


int bfs(int start, int d[], int p[]) {
	int farestVertex = -1;
	queue<int> q;
	for (int i = 0; i <= n; i++) {
		d[i] = -1;
		p[i] = -1;
	}
	d[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if (d[to] == -1) {
				d[to] = d[v] + 1;
				q.push( to );
				p[to] = v;
				if (farestVertex == -1 || d[to] > d[farestVertex]) {
					farestVertex = to;
				}
			}
		}
	}
	return farestVertex;
}


int d[MAX_N];
int p[MAX_N];
map<int,int> inDiam;

bool bamboo(int p, int v) {
	while (g[v].size() > 1) {
		if (g[v].size() > 2)
			return false;

		for(int i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if( to != p ) {
				p = v;
				v = to;
				break;
			}
		}
	}
	return true;
}

string solution()
{
	//calc diametre
	int v = bfs(1, d, p);
	v = bfs(v,d,p);

	vector<int> diam;
	diam.push_back(v);
	inDiam[v] = 1;
	
	while (p[v] != -1) {
		v = p[v];
		diam.push_back(v);
		inDiam[v] = 1;
	}

	for (int i = 0; i < diam.size(); i++) {
		v = diam[i];
		for (int j = 0; j < g[v].size(); j++) {
			int x = g[v][j];
			if (inDiam[x] == 0) {
				if (g[x].size() > 3) 
					return "No";

				for (int l = 0; l < g[x].size(); l++) {
					int y = g[x][l];
					if (y != v) {
						if (!bamboo(x,y)) return "No";
					}
				}
			}
		}
	}

	return "Yes";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int x,y;
		scanf("%d%d", &x, &y);
		e[i].first = x;
		e[i].second = y;
		g[x].push_back(y);
		g[y].push_back(x);
	} 

	cout << solution() << endl;

	return 0;
}