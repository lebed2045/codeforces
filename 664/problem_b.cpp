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


int n;
vector <int> a;

bool solutionExists(int i, int sum) {
	int sum_min = 0;
	int sum_max = 0;
	for (int j = i; j < a.size(); j++) {
		if (a[j] == 1) {
			sum_max += n;
			sum_min += 1;
		} else {
			sum_min -= n;
			sum_max -= 1;
		}
	}
	return sum_min <= sum && sum <= sum_max;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	string s;
	getline(cin, s);
	assert(s.find('=') != string::npos);
	n = stoi(s.substr(s.find('=')+2));

	a.push_back(1);
	for (int i = 0; s[i] != '='; i++) {
		if (s[i] == '+') {
			a.push_back(+1);
		} else if (s[i] == '-') {
			a.push_back(-1);
		}
	}
	dout(a);
	if (solutionExists(0,n)) {
		cout << "Possible\n"; 
		int m = n;

		for (int i = 0; i < (int)a.size(); i++) {
			bool exits = false;
			for (int x = 1; x <= n; x++) {
				if ( solutionExists(i+1, m - x*a[i]) ) {
					m -= x*a[i];
					if (i > 0) {
						cout << " " << (a[i] == 1 ? "+" : "-") << " ";
					}
					cout << x;
					exits = true;
					break;
				}
			}
			//dout(exits);
		}
		cout << " = " << n << "\n";
	} else {
		cout << "Impossible\n";
	}
	return 0;
}