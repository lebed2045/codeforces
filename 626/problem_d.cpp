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

const int MAX_A = 5000+10;

double solution(vector<int>& a) {
	sort(a.begin(), a.end());
	
	vector <int> d(MAX_A);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			d[ a[j] - a[i] ] += 1;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("%.7lf", solution(a));
	return 0;
}