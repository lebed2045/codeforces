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


int n;
int x = -1,y = -1;

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) x = i;
		if (temp == n) y = i;
	}
	if (x > y) swap(x,y);
	//cout << x << " " << y;
	assert(x >= 0 && y >= 0);
	if (x > (n-1-y) ) {
		x = 0;
	} else {
		y = n-1;
	}
	cout << y-x << "\n";
	return 0;
}