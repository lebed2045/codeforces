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

int n,p;
vector <int> l,r;
vector <double> vp;

void print_vector(vector <double> & v) {
	cout << "v = ";
	for (auto i: v) {
		cout << i << ",";
	}
	cout <<"\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		int li,ri;
		scanf("%d%d", &li, &ri);
		l.push_back(li);
		r.push_back(ri);
		vp.push_back( 1.0 - (double)((ri/p)-((li-1)/p)) / (ri-li+1) );
	}
	double answer = 0;
	for (int i = 0; i < n; i++) {
		answer += 2000.0 * (1 - vp[i]* vp[(i+1)%n]);
	}
	//print_vector(vp);
	printf("%.6lf", answer);
	return 0;
}