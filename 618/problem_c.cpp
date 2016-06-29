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
	vector < pair<pair<int,int>,int> > a(n);
	for (int i = 0; i < n; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		a[i].first.first = x;
		a[i].first.second = y;
		a[i].second = i + 1;
	}
/*
	for (int i = 0; i < n; i++) {
			dout(i);
			dout(a[i].first.first);
			dout(a[i].first.second);
		}
*/
	sort(a.begin(), a.end());

	for (int i = 0; i < 3; i++) 
		a.push_back(a[i]);

	for (int i = 0; i < n; i++) {
		auto p1 = a[i].first;
		auto p2 = a[i+1].first;
		auto p3 = a[i+2].first;
		long long x1 = p2.first - p1.first;
		long long y1 = p2.second - p1.second;
		long long x2 = p3.first - p1.first;
		long long y2 = p3.second - p1.second;
		if (x1*y2 - x2*y1 != 0) {
			printf("%d %d %d\n", a[i].second, a[i+1].second, a[i+2].second);
			break;
		}
	}
	return 0;
}