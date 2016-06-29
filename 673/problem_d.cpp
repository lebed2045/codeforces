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

int n,k;
int a,b,c,d;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	vector<int> v;
	for (int i = 1; i <= n; i++)
		if (i != a && i != b && i != c && i != d) {
			v.push_back(i);
		}

	if (n >= 5 && k >= 6 + (n-4-1)) {
		printf("%d %d ", a, c);
		for (auto &x: v) printf("%d ", x);
		printf("%d %d ", d, b);
		printf("\n");
		printf("%d %d ", c, a);
		for (auto &x: v) printf("%d ", x);
		printf("%d %d ", b, d);
		printf("\n");
	} else {
		printf("-1\n");
	}

	return 0;
}