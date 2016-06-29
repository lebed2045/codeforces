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

map<string,int> m;
long long solve(string s) {
	return m[s];
}



int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	string s;

	for (int i = 1989; i < 100000; i++) {
		s = to_string(i);
		for(int j = 1; j <= s.size(); j++) {
			if (m[s.substr(s.size()-j)] == 0) {
				m[s.substr(s.size()-j)] = i;
				break;
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> s;
		//IAO'2015
		cout << solve(s.substr(4)) << "\n";
	}
	return 0;
}