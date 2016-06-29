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

long long a,c,b;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	if( (c == 0 && a == b)  || ( c != 0 && (b-a)%c == 0 && ((c > 0 && a <= b) || (c < 0 && b <= a) ))   ) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}