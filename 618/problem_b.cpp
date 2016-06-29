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
	vector< vector<int> > a(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}

	vector <pair<int,int>> raw_with_max_amount(n+1);
	for (int i = 1; i <= n; i++) {
		map <int,int> m;
		for (int j = 1; j <= n; j++) 
			m[a[i][j]]++;
		for (auto &it: m) {
			if (raw_with_max_amount[it.first].first < it.second) {
				raw_with_max_amount[it.first] = make_pair(it.second, i);
			}
		}
	}

	vector <int> answer(n+1);

	for (int i = 1; i <= n; i++) {
		answer[ raw_with_max_amount[i].second ] = i;
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ",answer[i] == 0 ? n : answer[i]);
	}

	return 0;
}