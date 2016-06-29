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

int n,a,b,c,d;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> a >> b >> c >> d;
	vector <int> v = {a+b,b+d,d+c,c+a};
	sort(v.begin(), v.end());
	int d = (v[0]+n) - (v[3]+1) + 1;

	long long answer = 0;
	if (d > 0) {
		answer = (long long)n * d;
	}	
/*
	for (int i = 1; i <= n; i++) {
		int minS = v[2]+v[3] + 1 + i;
		int maxS = v[0]+v[1] + n + i;
		dout(minS);
		dout(maxS);
		int dD = maxS - minS + 1;
		if (dD > 0)
			answer += dD;
	}
*/
	cout << answer;
	return 0;
}