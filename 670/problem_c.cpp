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
#define ALL(x) (x).begin(),(x).end()

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

int n,m;
map<int,int> d;
vector<int> a,s;
typedef pair<int,int> pii;
typedef pair< pii, int > piii;
vector < piii > w;

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		d[temp] += 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		s.push_back(temp);
		w.push_back(  piii( pii(d[ a[i] ], d[ s[i] ] ), i+1 ) );
	}
	sort( ALL(w) );
	printf("%d\n", w[m-1].second);
	return 0;
}