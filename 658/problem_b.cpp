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

int n, k, q;
vector <int> a;
vector <bool> online(200000, false);
typedef pair<int,int> pii;
set< pii > s;
bool f(int q,int i) {
	if (q == 1) {
		// woke up
		s.insert( pii(a[i], i) );
		online[i] = true;
		if (s.size() > k) {
			auto bad = *s.begin(); s.erase(bad);
			online[bad.second] = false;
		}
	} else {
		return online[i];
	}
	return true;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}

	for (int i = 0; i < q; i++) {
		int typei,idi;
		scanf("%d%d", &typei, &idi);
		bool b= f(typei, idi-1);
		if (typei == 2) {
			printf("%s\n",b  ? "YES": "NO");	
		}
		
	}
	return 0;
}