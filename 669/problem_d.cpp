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

const int MAX_N = 1e+6+7;

int n, q;
vector <int> a(MAX_N);

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	//cin >> n >> q;
	scanf("%d%d", &n, &q);
	long long sh1 = 1;
	long long sh2 = 2;
	for (; q; --q) {
		//dout(sh1);
		//dout(sh2);
		int t, x;
		//cin >> t;
		scanf("%d", &t);
		if (t == 1) {
			//cin >> x;
			scanf("%d", &x);
			sh1 += x;
			sh2 += x;
		} else {
			//swap
			//dout("swap");
			if (sh1&1) sh1++; else sh1--;
			if (sh2&1) sh2++; else sh2--;
		}
		
	}

	//dout(sh1);
	//dout(sh2);
	for (int x = 1; x <= n; x+=2) {
		long long xi = sh1-1 + x-1;
		xi = ((xi%n)+n)%n;
		a[ xi ] = x;
	}
	for (int y = 2; y <= n; y+=2) {
		long long yi = sh2-2 + y-1;
		yi = ((yi%n) + n)%n;
		a[ yi ] = y;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	return 0;
}