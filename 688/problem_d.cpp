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
#include <unordered_map>
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

#define ALL(x) (x).begin(), (x).end()
//#define FORN(i,n) for (int i = 0; i < (int)n; i++) BS
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};

vi c;
queue<int> q;
priority_queue<int, std::vector<int>, std::greater<int> > pq;
string s;

int n,m,k;

map<vi,bool> used;
bool naiveSolve() {
	used.clear();
	for (int x = 1; x <= k; x++) {
		vi temp;
		for (int ci: c) {
			temp.pb(x % ci);
		}
		if (used.count(temp)) return false;
		used[temp] = true;
	}
	return true;
}



unordered_map<int,int> max_pow;
bool solve() {
	for (int ci: c) {
		int cc = ci;
		for (int d = 2; d*d <= cc; d++) {
			int d_pow = 0;
			while (ci%d == 0) {
				ci /= d;
				d_pow++;
			}
			max_pow[d] = max(max_pow[d], d_pow);
		}
		max_pow[ci] = max(max_pow[ci], 1);
	}
	for (int d=2; d <= k; d++) {
		if (max_pow[d]) {
			cout << d << "^" << max_pow[d] << "\n";
		}
	}


	long long max_mod = 1;
	for (int d = 2; d <= k; d++) {
		if (max_pow[d]) {
			for (int j = 0; j < max_pow[d]; j++) {
				max_mod *= (long long)d;
			}
			if (max_mod >= k) {
				return true;
			}
		}
	}
	return false;
}

void solution() {
	/*
	int kk = k;
	for (k = kk; k < kk+200; k++) {
		if (solve() != naiveSolve()) {
			cout << "alaarm, k = " << k << "\n";
		}
	}
	dout(naiveSolve());
	*/
	/*
	if (solve()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	*/
	long long common = 1;
	for (int ci: c) {
		common = (common*ci / __gcd((int)common,ci))%k;
	}
	if (common == 0) { // common%K == 0
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

void readData() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int ci;
		scanf("%d", &ci);
		c.pb(ci);
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	solution();
	return 0;
}