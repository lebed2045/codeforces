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

const int MOD = 1e9+7;

int char2code(int ch) {
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	} else
	if ('A' <= ch && ch <= 'Z') {
		return 10 + ch - 'A';
	} else 
	if ('a' <= ch && ch <= 'z') {
		return 36 + ch - 'a';
	} else 
	if (ch == '-') {
		return 62;
	} else 
	if (ch == '_' ){
		return 63;
	} else {
		assert(false);
	}
}

string s;
map <int,int> m;

int solution() {
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			m[x&y]++;
		}
	}
	long long result = 1;
	for (int i = 0; i < s.size(); i++) {
		result *= m[ char2code(s[i]) ];
		result %= MOD;
	}
	return (int)result;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> s;
	//dout(s);
	cout << solution() << "\n";
	return 0;
}