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
//std::vector<int> v;
std::vector<int> b(100, 1);


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		b[temp] = 0;
	}
	int nb = 0;
	int answer = 90;
	for (int i = 1; i <= 90; i++) {
		if (b[i]) nb++; else nb = 0;
		if (nb == 15) {
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}