#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

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

int n, k;
vector <int> v;


int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	long long said = 0;
	for (int i = 0; i < n; i++) {
		said += (i+1);
		if (said >= k) {
			int j = i;
			while (said > k) {
				j -= 1;
				said -= 1;
			}	
			printf("%d\n", v[j]);
			return 0;
		}
	}
	return 0;
}