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

int n,k;
const int MAX_N = 1000000;
vector <int> a;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back( temp );
		sum += temp;
	}
	sort( a.begin(), a.end() );
	int avr = sum / n;
	long long eq = 0;
	for (int i = 0; i < n; i++) {
		eq += abs(a[i] - avr);
	}
	if (eq <= k) {
		if ( avr*n == sum ) {
			cout << "0\n";
		} else {
			cout << "1\n";
		}
		return 0;
	}


	int l = 0;
	int r = n-1;
	long long pref = 0;
	long long suff = 0;
	long long m = a[l];
	long long M = a[r];

	while (l < r) {
		if (pref < suff) {
			l += 1;
			long long add = (a[l] - m) * l;
			if (pref + add > k) {
				add = min(add, k - pref);
				if (add) {
					pref += add;
					m += add / l;	
				}
			} else{
				pref += add;	
				m = a[l];
			}
		} else {
			r -= 1;
			long long add = (M - a[r]) * (n - r - 1);
			if (suff + add > k) {
				add = min(add, k - suff);
				if (add) {
					suff += add;
					M -= add / (n - r - 1);
				}
			} else {
				suff += add;	
				M = a[r];
			}
		}
	}
	cout << M - m;


	return 0;
}