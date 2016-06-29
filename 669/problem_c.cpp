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

int n, m, q;
const int INF = 1e9 + 7;
const int MAX_N = 100+7;
vector < vector<int> > a(MAX_N, vector<int> (MAX_N,INF));

typedef pair<int,int> pii;
vector <pii> vq;

void shiftRaw(int r) {
	for (int c = 1; c <= m; c++) {
		a[r][c-1] = a[r][c];
	}
	a[r][m] = a[r][0];
}

void shiftColumn(int c) {
	for (int r = 1; r <= n; r++) {
		a[r-1][c] = a[r][c];
	}
	a[n][c] = a[0][c];
}

void shiftRaw2(int r) {
	for (int c = m; c >= 1; --c) {
		a[r][c+1] = a[r][c];
	}
	a[r][1] = a[r][m+1];
}

void shiftColumn2(int c) {
	for (int r = n; r >= 1; --r) {
		a[r+1][c] = a[r][c];
	}
	a[1][c] = a[n+1][c];
}

void solve() {
	
	for (int i = vq.size()-1; i >= 0; --i) {
		int ti = vq[i].first;
		if (ti == 1) {
			int ri = vq[i].second;
			shiftRaw2(ri);
		}
		if (ti == 2) {
			int ci = vq[i].second;
			shiftColumn2(ci);
		}
	}
	
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			printf("%d ",a[r][c] != INF ? a[r][c] : 0);
		}
		printf("\n");
	}
}



void readData() {
	cin >> n >> m >> q;
	int ti, ri, ci, xi;
	for (; q; --q) {
		cin >> ti;
		if (ti == 1) {
			cin >> ri;
			assert(ri <= n);
			shiftRaw(ri);
			vq.push_back( pii(1,ri) );
		}
		if (ti == 2) {
			cin >> ci;
			assert(ci <= m);
			shiftColumn(ci);
			vq.push_back( pii(2,ci) );
		}
		if (ti == 3) {
			cin >> ri >> ci >> xi;
			a[ri][ci] = xi;
		}
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	dout(INF);
	readData();
	solve();
	return 0;
}