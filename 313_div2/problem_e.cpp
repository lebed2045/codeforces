
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define dout(x) cout << (#x) << " = " << (x) << endl

typedef long long ll;

const int MAX_N = 2000+9;
const int MAX_X = 250000;
const long long MOD = 1000000000+7;
int h,w,n;
vector < pair<int,int> > v;
long long d[MAX_N];

long long binpowByModulo(long long a, int n) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res = (res*a) % MOD;
		a = (a*a) % MOD;
		n >>= 1;
	}
	return res;
}

long long modularMultiplicativeInverse(long long x) {
	return binpowByModulo(x, MOD-2);
}

long long factorialByModulo(long long x) {
	//lazy preculc
	static vector <int> _f;
	if (_f.size() == 0) {
		_f.resize(MAX_X);
		_f[0] = 1;
		for (int i = 1; i < MAX_X; i++) {
			_f[i] = ((long long)_f[i-1]*i) % MOD;
		}
	}
	return _f[x];
}

long long C(int k,int n) {
	//n! / (k!*(n-k)!)
	return (factorialByModulo(n) * modularMultiplicativeInverse( (factorialByModulo(k)*factorialByModulo(n-k)) % MOD )) % MOD;
}

long long numberOfAllPaths(int x,int y) {
	return C(x-1, x+y-2);
}

int solution() {
	sort(v.begin(), v.end());
	for (int i = 0; i <= n; i++) {
		//calc d[i]

		//all paths
		long long di_ = numberOfAllPaths(v[i].first, v[i].second);
		//dout(di_);

		//minus illigal paths
		for (int j = 0; j < i; j++) 
			if (v[j].first <= v[i].first && v[j].second <= v[i].second){
				//j is the first black cell
				di_ -= (d[j]*numberOfAllPaths(v[i].first - v[j].first+1, v[i].second - v[j].second + 1)) % MOD;
				di_ = (di_ + 10*MOD) % MOD;
			}
		d[i] = di_;
		//dout(d[i]);
	}
	return d[n];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	cin.sync_with_stdio(false);
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		int ri, ci;
		cin >> ri >> ci;
		v.push_back( make_pair(ri,ci) );
	}
	v.push_back( make_pair(h,w) );

	cout << solution() << endl;

	return 0;
}
/*
1 1 1 
1 2 3
1 3 6
1 4 10
*/