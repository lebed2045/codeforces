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
#define ALL(x) (x).begin(), (x).end()

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

struct RSQ {
	int n;
	vector <int> a;
	void create(int n_) {
		n = n_;
		a.assign(n_*4, 0);
	}
	void add(int pos, int value, int node = 1, int l = 1, int r = -1) {
		if (r == -1) r = n;
	
		if (l <= pos && pos <= r ) {
			a[node] += value;
			if (l < r) {
				int m = (l+r) / 2;
				add(pos, value, node*2, l, m);
				add(pos, value, node*2+1, m+1, r);
			}
		}
	}

	int sum(int ql, int qr, int node = 1, int l = 1, int r = -1) {
		if (r == -1) r = n;
		//temp
		if (qr < l || r < ql || l > r ) return 0;	

		if (ql <= l && r <= qr) return a[node];

		int m = (l+r) / 2;
		return 	sum(ql, qr, node*2, l, m) +
				sum(ql, qr, node*2+1, m+1, r);


	}
};

void test_RSQ() {
	RSQ r;
	r.create(3);
	r.add(1, 11);
	r.add(3, 22);
	dout(r.a);
	dout(r.sum(1,2));
}

int n;
vector <int> a, t, x;
map<int,int> x2xx;
map<int, map<int,int> > x2t2tt;
map<int, RSQ> x2rsq;

void solve() {
	for (auto xi: x) {
		x2xx[xi] = 1;
	}
	for (auto &xii: x2xx) {
		auto &t2tt = x2t2tt[xii.first];
		int tt_size = 0;
		for (auto &tt: t2tt) {
			tt.second += tt_size;
			tt_size += 1;
		}
	}
	for (auto xii: x2xx) {
		int x = xii.first;
		x2rsq[x].create(x2t2tt[x].size()+2);
		//dout(x2rsq[x].a.size());
	}


	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			x2rsq[ x[i] ].add( x2t2tt[ x[i] ][ t[i] ], 1 );
		}
		if (a[i] == 2) {
			x2rsq[ x[i] ].add( x2t2tt[ x[i] ][ t[i] ], -1 );
		}
		if (a[i] == 3) {
			int number = x2rsq[ x[i] ].sum(1, x2t2tt[ x[i] ][ t[i] ]);
			printf("%d\n", number);
		}
	}
}

void readData() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ai, ti, xi;
		scanf("%d%d%d", &ai, &ti, &xi);
		a.push_back(ai);
		t.push_back(ti);
		x.push_back(xi);
		x2t2tt[xi][ti] = 1;
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
	//test_RSQ();
	return 0;
}