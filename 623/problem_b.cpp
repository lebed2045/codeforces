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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());
	int last = 1e9+7;
	long long answer = 0;
	for (int i = a.size()-1; i >= 0; i--) {
		last = a[i] = max(0 ,min(a[i], last-1));
		answer += a[i];
	}
	cout << answer;

	dout(a);

	return 0;
}