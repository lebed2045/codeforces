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

int n;
string s;

bool f (int x,int y) {
	int X = 0;
	int Y = 0;
	for (int i = x; i <= y; i++) {
		if (s[i] == 'U') X++;
		if (s[i] == 'D') X--;
		if (s[i] == 'L' ) Y--;
		if (s[i] == 'R') Y++;
	}
	return X == 0 && Y == 0;
}

int solution() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (f(i,j)) result += 1;
		}
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	cout << solution();
	return 0;
}