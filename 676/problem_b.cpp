#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

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

int n,t;
const double EPS = 1e-8;

int solve(int n,int t) {
	int answer = 0;
	vector< vector<double> > v(n+1);
	for (int i = 0; i < (int)v.size(); i++) {
		v[i] = vector<double>(i+1);
	}
	v[0][0] = t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			if (v[i][j] >= 1-EPS) {
				double temp = (v[i][j] - 1) / 2.0;
				v[i+1][j] += temp;
				v[i+1][j+1] += temp;
				v[i][j] = 1.0;
				answer += 1; // v[i][j]
			}
		}
	}
	return answer;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> t;
	cout << solve(n,t) << "\n";
	return 0;
}