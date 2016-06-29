#include <cstdio>
#include <cstring>
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

int n;
long long answer = 0;
vector <int> v;

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	scanf("%d", &n);	
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (auto vi: v) {
		answer -= vi;
	}
	answer += v[n-1]*2;
	assert(answer >= 0);
	cout << answer + 1 << "\n";
	return 0;
}