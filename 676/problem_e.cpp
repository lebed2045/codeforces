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

int n, k;
int m;
vector <int> a;
const int ALT = 100500;
bool humanFirst = false;

bool humanWins() {
	if (m&1) {
		humanFirst = true;
	}
	if (k == 0) {
		if (a[0] == 0 || (a[0] == ALT && humanFirst)) {
			return true;
		} else {
			return false;
		}
	} else {
		if (m == n+1) {
			long long MOD = 10050032412414ll;
			long long res = 0;
			long long x = 1;
			for (int i = 0; i <= n; i++) {
				res += a[i]*x;
				x *= k;
				res %= MOD;
				x %= MOD;
			}
			return (res == 0);
		} else {
			return (n+1)%2 == 0;
		}
	}
	return false;
}

void readData() {
	cin >> n >> k;
	m = 0;
	for (int i = 0; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "?") {
			a.push_back(ALT); 
		} else {
			m++;
			a.push_back(stoi(s));
		}
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	if (humanWins()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}