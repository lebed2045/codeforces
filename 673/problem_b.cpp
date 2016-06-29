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


int n,m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d %d", &n, &m);

	int last_div2 = 1;
	int first_div1 = n;

	for (int i = 0; i < m; i++) {
		int x,y;
		scanf("%d %d", &x,&y); if (x > y) swap(x,y);
		cerr << x << " = " << y << endl;
		
		last_div2 = max(last_div2,x);
		first_div1 = min(y,first_div1);
	}
	

	if (last_div2 < first_div1) {
		printf("%d\n", first_div1 - last_div2);
	} else {
		printf("0\n");
	}
	return 0;
}