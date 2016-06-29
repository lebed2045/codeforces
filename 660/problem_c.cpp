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

int n, k;
vector <int> a;


queue<int> q;
void solve() {
	int m = k;
	int max_len = 0;
	int max_i = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			while (m == 0 && !q.empty() && q.front() == 1) {
				q.pop();
			}
			if (m == 0 && !q.empty() && q.front() == 0) {
				q.pop();
				m++;
			}
			if (m > 0) {
				m--;
				q.push(a[i]);
			}
		} else {
			q.push(a[i]);
		}
		if (q.size() > max_len) {
			max_len = q.size();
			max_i = i;
		}
	}
	while (max_i >= 0) {
		if (a[max_i] == 0) {
			if (k > 0) {
				a[max_i] = 1;
				k--;
			} else {
				break;
			}
		} else {

		}
		max_i--;
	}

	printf("%d\n", max_len);
	for (auto ai: a) {
		printf("%d ", ai);
	}
}

void readData() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
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