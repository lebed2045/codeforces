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

const int MAX_N = 1e5+10;
char s[MAX_N];
int n,k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (k > 0) {
			if (k > max(s[i] - 'a', 'z' - s[i])) {
				if (s[i] - 'a' > 'z' - s[i]) {
					k -= s[i] - 'a';
					s[i] = 'a';
				} else {
					k -= 'z' - s[i];
					s[i] = 'z';
				}
			} else {
				if (k <= s[i] - 'a') {
					s[i] -= k;
					k = 0;
				} else {
					s[i] += k;
					k = 0;
				}
			}
		}
	}
	if (k > 0) {
		printf("-1\n");
	} else {
		printf("%s\n", s);
	}
	return 0;
}