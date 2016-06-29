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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n > 26) {
		cout << "-1\n";
	} else {
		string s;
		map<int,int> m;
		cin >> s;
		int diff = 0;
		for (char ch: s) {
			if (m[ch] == 0) {
				m[ch] = 1;
				diff++;	
			} 
		}
		cout << s.size() - diff;
	}
	return 0;
}