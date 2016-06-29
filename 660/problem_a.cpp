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

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
#endif
	int n;
	vector <int> a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	vector<int> v;
	for (auto ai: a) {
		if (v.size() > 0 && __gcd(v[v.size()-1],ai) != 1 ) {
			v.push_back(1);
		}
		v.push_back(ai);
	}

	cout << v.size() - n << "\n";
	for (auto vi: v) {
		cout << vi << " ";
	}

	return 0;
}