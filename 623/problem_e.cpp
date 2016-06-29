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
    for(auto vi: v)
        out << vi << ",";
    out << "]";
    return out;
}

const int MAX_N = 1e5+10;
const double EPS = 1;
int n;
vector<long long> x(MAX_N), y(MAX_N);


long long diameter(vector<long long> x) {
	sort(x.begin(), x.end());
	return (0ll + x[n-1] - x[0])*(x[n-1] - x[0]);
}

double minRadiusXY(double x0, double y0) {
	double maxDist = 0;
	for (int i = 0; i < n; i++) {
		double dist = min( (x[i] - x0)*(x[i] - x0), (y[i] - y0)*(y[i] - x0));
		maxDist = max(maxDist, dist);
	}
	return maxDist;
}

double minRadiusX(double x0) {
	long double l = -1e9;
	long double r = 1e9; 
	while (r - l > EPS) {
   		double m1 = l + (r - l) / 3;
      	double m2 = r - (r - l) / 3;
   		if (minRadiusXY(x0, m1) > minRadiusXY(x0, m2)) {
      		l = m1;
   		}
   		else {
      		r = m2;
   		}
	}
	return minRadiusX(l);
}

long long solution() {
	// all on x;
	long long d = min(diameter(x),diameter(y));
	// ternar search X0
	double l = -1e9;
	double r = 1e9; 
	while (r - l > EPS) {
   		double m1 = l + (r - l) / 3;
      	double m2 = r - (r - l) / 3;
   		if (minRadiusX(m1) > minRadiusX(m2))
      		l = m1;
   		else
      		r = m2;
	}
	double dd = minRadiusX(l)*2;
	long long minSqrDiameter = dd*dd;
	return min(minSqrDiameter, d);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int xi, yi;
		scanf("%d%d", &xi, &yi);
		x[i] = xi;
		y[i] = yi;
	}
	x.resize(n);
	y.resize(n);
	dout(minRadiusX(0));
	//cout << solution();
	return 0;
}