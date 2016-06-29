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
#define endl "\n"

long long readNumber() {
	int n, base;
	long long number = 0;
	cin >> n >> base;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		number *= base;
		number += temp;
	}
	//dout(number);
	return number;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	long long a = readNumber();
	long long b = readNumber();

	if (a == b) {
		cout << "=" << endl;
	} else {
		cout << (a < b ? "<" : ">") << endl;
	}


	return 0;
}