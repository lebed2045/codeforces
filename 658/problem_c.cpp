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

int n,d,h;
typedef pair<int,int> pii;
vector <pii> a;
#define pb push_back

bool f() {
	if (h == 1) {
		if (d == 1) {
			if (n == 2) {
				a.pb(pii(1,2));
			} else return false;
		} else if (d == 2){
			// hedge
			for (int i = 2; i <= n; i++ ) {
				a.pb(pii(1,i));
			}
		} else {
			//d > 2
			return false;
		}
	} else {
		// h >= 2
		if (d > 2*h) return false;
		int v = 1;
		for (int i = 1; i <= h; i++) {
			v++;
			//printf("%d %d\n", i, i+1)
			a.pb(pii(i, v));
			
		}
		for (int i = h; i < d; i++) {
			v++;
			if (i == h)
				a.pb( pii(1,v) );
			else
				a.pb( pii(v-1,v) );
		}
		for (int i = v+1; i <= n; i++) {
			v++;
			a.pb(pii(2,v));
			
		}

		if (v > n) return false;
	}
	return true;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> d >> h;
	if (!f()) {
		cout << "-1\n";
	} else
	for(auto ai:a) {
		printf("%d %d\n", ai.first, ai.second);
	}
	return 0;
}