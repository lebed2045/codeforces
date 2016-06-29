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

int n, k, h;
vector <int> a;

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d%d", &n, &h, &k);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	long long time = 0;
	int comb = 0;
	int i = 0;
	while (i<n || comb > 0) {
		while (i < n && h - comb >= a[i]) {
			comb += a[i];
			i++;
		}
		if (i<n) {
			int t = a[i] - (h-comb);
			if (t > 0) {
				int tt = t / min(comb,k);
				time += tt;
				comb -= min(comb,k)*tt; 	
			}
			
		} else {
			int t = comb;
			if (t > 0) {
				int tt = t / min(comb,k);
				time += tt;
				comb -= min(comb,k)*tt; 	
			}
		}
		if (i < n && h-comb >= a[i]) continue;
		if (comb > 0) {
			comb -= min(comb,k);
			time++;
		}
	}
	cout << time << "\n";
	
	return 0;
}