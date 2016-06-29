#include <cstdio>
#include <cstring>
#define M_PI 3.14159265359
#include <cmath>
#include <cassert>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;
#define ALL(x) (x).begin(), (x).end()

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}
/*
void binarySearch() {
	int L = minValue - 1, R = maxValue + 1;
	while (R - L > 1) {
	    int M = (L + R) / 2;
	    if (check(M)) {
	        R = M;
	    } else {
	        L = M;
	    }
	}
	return {L,R}
}
*/
int n;
string s;
vector<int> d;

string solution() {
	int i = 0;
	while (0 <= i && i < n) {
		if (d[i] == -1) {
			return "INFINITE";
		}
		int j = i + d[i]*(s[i] == '>' ? 1: -1);	
		d[i] = -1;
		i = j;
	}
	return "FINITE";
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}
	cout << solution() << "\n";
	return 0;
}