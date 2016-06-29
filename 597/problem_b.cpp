#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

typedef long long ll;

const int MAX_N = 1*1000*1000+9;

int n;
pair <int,int> a[MAX_N];
int res[MAX_N];
vector <int> endsHereId[MAX_N];

int solve() {
	//points compression
	map<int, int> time2i;
	for (int i = 0; i < n; i++) {
		time2i[ a[i].first ] = 0;
		time2i[ a[i].second ] = 0;
	}
	int i = 1;
	for (auto it = time2i.begin(); it != time2i.end(); it++, i++) {
		it->second = i;
	}
	for (int i = 0; i < n; i++) {
		a[i].first = time2i[ a[i].first ];
		a[i].second = time2i[ a[i].second ];
	}

	for (int i = 0; i < n; i++) {
		endsHereId[ a[i].second ].push_back(i);
	}
	memset(res, 0, sizeof res);
	int maxRes = 0;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < (int)endsHereId[i].size(); j++) {
			int k = endsHereId[i][j];
			int l = a[k].first;
			int r = a[k].second;
			//assert(r == i);
			int currRes = res[l-1] + 1;
			if (currRes > maxRes) maxRes = currRes;
		}
		res[i] = maxRes;
	}
	return maxRes;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		a[i].first = l;
		a[i].second = r;
	}
	cout << solve() << endl;
}