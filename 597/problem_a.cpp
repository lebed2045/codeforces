#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

typedef long long ll;

ll solve(ll k, ll a, ll b) {
	if (a <= 0 && 0 <= b) {
		//[a .. 0 .. b]
		return abs(a)/k + 1 + b/k;
	} else {
		// if negative
		if (a < 0) {
			// mirror
			ll temp = -a;
			a = -b;
			b = temp;
			
			
			dout(a);
			dout(b);
			dout(b/k - (a-1)/k);
			
		}
		//[0 .. b]
		if (a == 0) return b/k + 1;
		// 0 < [a .. b]
		return b/k - (a-1)/k;
	}
}

int nativeSolve(ll k, ll a, ll b) {
	int res = 0;
	for (ll x = a; x <= b; x++) {
		if (x%k == 0) res++;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
/*
	for (int k = 1; k < 100; k++)
	for (int a = -100; a < 100; a++) {
		for (int b = a; b < 100; b++) {
			if (nativeSolve(k, a, b) != solve(k, a, b)) {
				cout << "error!";
				cout << k << " " << a << " " << b << " native = " << nativeSolve(k,a,b) << ", solve = " << solve(k, a, b) << endl;
				return 0;	
			} 
		}
	}
*/
	ll k, a, b;
	cin >> k >> a >> b;
	cout << solve(k, a, b) << endl;
}