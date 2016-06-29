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

int n,k;
string s;

int solutionA() {
	int b = k;
	int answer = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			q.push('a');
		} else {
			if (b > 0) {
				b -= 1;
				q.push('b');
			} else {
				while (!q.empty() && q.front() != 'b') {
					q.pop();
				}
				if (!q.empty() && q.front() == 'b') {
					b += 1;
					q.pop();
				}
				if (b > 0) {
					b -= 1;
					q.push('b');
				}
			}
		}
		answer = max(answer, (int)q.size());
		//dout(i);
		//dout(answer);
	}
	return answer;
}


int solve() {
	int answer = solutionA();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') s[i] = 'b'; else s[i] = 'a';
	}

	answer = max (answer, solutionA() );
	cout << answer << "\n";
	return 0;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> k;
	getline(cin, s);
	getline(cin, s);
	solve();
	return 0;
}