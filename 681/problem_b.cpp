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
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

#define ALL(x) (x).begin(), (x).end()
#define FORN(i,n) for (int #i = 0; #i < (int)(n); #i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};





int n,m,k,q,t;


void solve() {
	for (int a = 0; a <= n/1234567; a++ ) {
		int temp = (n-a*1234567)/123456;
		for (int b = 0; b <= temp; b++) {
			if ( (n - a*1234567 - b*123456) % 1234 == 0) {
				cout << "YES\n";
				int c = (n - a*1234567 - b*123456) / 1234;
				dout(a*1234567 + b*123456 + c*1234);
				return;
			}
		}
	}

	cout << "NO\n";
}

void readData() {
	cin >> n;
	dout(n);
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	solve();
	return 0;
}