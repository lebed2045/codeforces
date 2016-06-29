
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define dout(x) cout << (#x) << " = " << (x) << endl

typedef long long ll;

const int MAX_N = 200000+9;
//const int MAX_Q = 500000+9;
int n,q;
int _parent[MAX_N];
int _rank[MAX_N];
vector<int> alreadyUnitedUpTo (MAX_N);


void make_set (int v) {
	_parent[v] = v;
	_rank[v] = 0;
}
 
int find_set (int v) {
	if (v == _parent[v])
		return v;
	return _parent[v] = find_set (_parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (_rank[a] < _rank[b])
			swap (a, b);
		_parent[b] = a;
		if (_rank[a] == _rank[b])
			++_rank[a];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	//cin.sync_with_stdio(false);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		make_set(i+1);
	}
	for (int i = 0; i < q; ++i) {
		int t,x,y;
		scanf("%d%d%d", &t, &x, &y);

		if (t == 1) {
			union_sets(x,y);
		}

		if (t == 2) {
			for (int j = x; j < y; ++j) {
				if (alreadyUnitedUpTo[j] == 0 ) {
					alreadyUnitedUpTo[j] = y;
				} else {
					int jump = alreadyUnitedUpTo[j];
					alreadyUnitedUpTo[j] = max(alreadyUnitedUpTo[j], y);
					j = min(y-1, jump);
				}
				union_sets(j, j+1);

			}
		}

		if (t == 3) {
			if (find_set(x) == find_set(y)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}
