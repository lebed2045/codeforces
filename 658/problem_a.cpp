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

int n, c;
	vector <int> p,t;

long long score(vector<int> p, vector <int> t) {
	long long res = 0;
	int T = 0;
	for (int i = 0; i < n; i++) {
		T += t[i];
		res += max(0, p[i] - c*T);
	}
	return res;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		p.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		t.push_back(temp);
	}
	long long limkak = score(p,t);
	reverse(ALL(p));
	reverse(ALL(t));
	long long rade = score(p,t);
	if (limkak == rade) {
		cout << "Tie\n";
	}
	if (limkak > rade) {
		cout << "Limak\n";
	}
	if (limkak < rade) {
		cout << "Radewoosh\n";
	}
	return 0;
}