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
	scanf("%d", &n);
	std::vector<int> a;
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x%2 == 0) 
			answer += x;
		else
			a.push_back(x);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	long long y = 0;
	for (auto x: a) {
		if (y == 0) {
			y = x;
		} else {
			answer += y+x;
			y = 0;
		}
	}
	cout << answer;
	return 0;
}