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

std::vector<int> a;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}

	std::vector<int> longest_curr_min({1}), longest_max({1});
	int result = 0;
	for (int i = 1; i < n; i++) {
		int curr_min, curr_max;
		if (a[i - 1] == a[i]) {
			curr_max =  1 + longest_max[i - 1];
			curr_min =  1 + longest_curr_min[i - 1];
		} else if (a[i-1] < a[i]) {
			curr_max = 1;
			curr_min = 1 + longest_max[i-1];
		} else {
			curr_max = 1 + longest_curr_min[i-1];
			curr_min = 1;

		}
		longest_max.push_back(curr_max);
		longest_curr_min.push_back(curr_min);
		result = max(result, curr_max);
		result = max(result, curr_min);
	}

	cout << result << endl;

	return 0;
}