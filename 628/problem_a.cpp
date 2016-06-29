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

int n,b,p;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> b >> p;
	int m = n;
	int k = 1;
	int x = 0;
	int y = n*p;
	
	while (m > 1) {
		for (k = 1; k*2 <= m; k*=2){}
		x += (k/2)*1 + k*b;
		m = (m-k) + k/2;	
	}
	cout << x << " " << y << endl;
	return 0;
}