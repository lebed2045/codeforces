#include <cstdio>
#include <cstring>
#define M_PI 3.14159265359
#include <cmath>
#include <cassert>

#include <iostream>
#include <iomanip>
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

double d,h,v,e;

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> d >> h >> v >> e;
	double area = (d/2)*(d/2)*M_PI;
	double h_plus = e;
	double h_minus = v / area;
	cout.precision(20);
	if (h == 0 || h_minus > h_plus) {
		cout << "YES\n" << h / (h_minus - h_plus) << "\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}