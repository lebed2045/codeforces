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

/*
void binarySearch() {
	int L = minValue - 1, R = maxValue + 1;
	while (R - L > 1) {
	    int M = (L + R) / 2;
	    if (check(M)) {
	        R = M;
	    } else {
	        L = M;
	    }
	}
	return {L,R}
}
*/

long long m; // m <1e+15 , sqrt(m) < 3.5 * 1e+7

int f(long long m){
	int res = 0;
	while (m) {
		long long base = pow((long double)m+0.0001, 1.0/3); 
		//dout(base);
		base--;
		while ((base+1)*(base+1)*(base+1) <= m) {
			base++;
			//dout(base);
		}
		m -= base*base*base;
		res++;
		//dout(m);
	}
	return res;
}

void solve() {
	long long max_m = m;
	long long max_b = f(m);
	
	for (int i = 5*1e+5; m > 0 && i > 0; m--, i--) {
		int temp = f(m);
		if (temp > max_b) {
			max_b = temp;
			max_m = m;
		}
	}
	cout << max_b << " " << max_m;
}

void test() {
	long long base = 1;
	long long sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += base*base*base;
		cout << base << " " << sum << "\n";
		base++;
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> m;
	//test();
	solve();
	return 0;
}