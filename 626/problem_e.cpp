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

const int MAX_N  = 205000;

int n;
vector <int> x;
long long pref[MAX_N], suff[MAX_N];


long double f(int l,int r) {
	int len = l+1 + n-r;
	long double mean = (pref[l] + suff[r]) / (long double)len;
	long double median = 0;
	if (len % 2 == 0) {
		median = (x[l] + x[r]) / 2.0;
	} else {
		median = x[l];
	}
	return mean - median;
}

void solution() {
	if (n == 1) {
		printf("1\n%d",x[0]);
		return;
	}
	int res_l = 0;
	int res_r = n-1;
	long long res = -1000000000;

	sort(x.begin(), x.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) pref[i] = x[i]; else pref[i] = pref[i-1] + x[i];
	}
	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) suff[i] = x[i]; else suff[i] = x[i] + suff[i+1];
	}

	for (int r = n-1; r >= n/2; r--) {
		for (int l = (n-1-r); l < r && l < (n-1-r+2); l++)
			if (f(l,r) > res) {
				res_l = l;
				res_r = r;
				res = res = f(l,r);
			}
	}

	vector <int> answer;
	for (int i = 0; i <= res_l; i++) 
		answer.push_back(x[i]);
	for (int i = n-1; res_r <= i; i--)
		answer.push_back(x[i]);

	printf("%d\n", (int)answer.size());
	for (auto i: answer) {
		printf("%d ", i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		x.push_back(temp);
	}

	solution();

	return 0;
}