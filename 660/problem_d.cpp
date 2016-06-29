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

int n;
#define x first
#define y second
typedef pair<int,int> pii;
vector <pii> a;
long long default_angle = 100500+rand();


map<long double, vector<pii> > m;
inline long double getAngle(int i, int j) {
	int dx = a[j].x - a[i].x;
	int dy = a[j].y - a[i].y;
	if (dx != 0 && dy != 0) {
		int g = __gcd(dx,dy);
		dx /= g;
		dy /= g;
	}
	long double angle = default_angle;
	if (dy != 0) {
		angle = (long double)dx / dy;
	}
	return angle;
}
void solve() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			long double angle = getAngle(i,j);
			m[angle].push_back(pii(i,j));
		}
	}
	for (auto it: m) {
		vector <pii> &v = it.second;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				if (getAngle( v[i].x, v[j].x ) == getAngle( v[i].y, v[j].y ) ||
					getAngle( v[i].x, v[j].y ) == getAngle( v[i].y, v[j].x ) ) {
					answer += 1;
				}
			}
		}
	}
	cout << answer/2 << "\n";
}

void readData() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		a.push_back( pii(xx,yy) );
	}
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