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

const int MAX_N = 3*1e5+10;
char s[MAX_N];

long long solve() {
	long long answer = 0;
	int digit, lastDigit;
	for (int i = 0; s[i] != 0; i++) {
		digit = s[i]-'0';
		if (i == 0) {
			if (digit % 4 == 0) answer += 1;
		} else {
			int lastDigits = lastDigit*10 + digit;
			if (lastDigits%4 == 0) {
				answer += i;
			}
			if (digit % 4 == 0) answer += 1;
		}
		lastDigit = digit;
	}
	return answer;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%s", s);
	cout << solve();
	return 0;
}