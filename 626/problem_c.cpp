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

int n,m;

bool isPossible(int a) {
	return (a/2 + a/3 - a/6 >= n+m) && (a/2 >= n) && (a/3 >= m);
}

int solution() {
	int answer = 0;
	while (!isPossible(answer)) {
		answer += 1;
	}
	return answer;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cout << solution();
	return 0;
}