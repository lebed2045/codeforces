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

int n, m;
vector <int> answer;
const int  _left = 1;
const int  _right = 0;

void solve() {
	vector < map<int,vector<int>> > bus(n);
	// get in
	for (int p = 1; p <= m; p++) {
		bool b = false;
		// window
		for (int i = 0; i < n; i++) {
			if (bus[i][ _left].size() == 0) {
				bus[i][ _left].push_back(p);
				b = true;
				break;
			}
			if (bus[i][ _right].size() == 0) {
				bus[i][ _right].push_back(p);
				b = true;
				break;
			} 
		}
		if (b) continue;
		// hall
		for (int i = 0; i < n; i++) {
			if (bus[i][ _left].size() <= 1) {
				bus[i][ _left].push_back(p);
				break;
			}
			if (bus[i][ _right].size() <= 1) {
				bus[i][ _right].push_back(p);
				break;
			} 
		}
	}
	//get out
	for (int i = 0; i < n; i++) {
		while (bus[i][ _left].size() > 0) {
			int p = bus[i][ _left].back(); 
			bus[i][ _left].pop_back();
			answer.push_back( p );	
		}
		while (bus[i][ _right].size() > 0) {
			int p = bus[i][ _right].back(); 
			bus[i][ _right].pop_back();
			answer.push_back( p );	
		}
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	solve();
	for (auto a: answer) {
		cout << a << " ";
	}
	return 0;
}