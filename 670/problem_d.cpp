#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

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

int n, k;
vector <int> a,b;

bool canCook(long long x) {
	int kk = k;
	for (int i = 0; i < n; i++) {
		if (a[i] * x <= b[i]) continue;
		if ((a[i] * x - b[i]) <= kk) {
			kk -= (a[i]*x - b[i]);
		} else return false;
	}
	return true;
}

int solve() {
	long long l = 0;
	long long r = 1e10;
	while (r-l > 1) {
		long long m = (l+r)/2;
		if (canCook(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		b.push_back(temp);
	}
	printf("%d\n", solve());
	return 0;
}