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

const int MAX_M = 2500;
const int MOD = 1e9 + 7;



namespace solution{
	int n;
	int m;
	int d;
	string a,b,c;

	long long _f[MAX_M][MAX_M][2][2];

	long long f(int j, int rest, bool isPreffixEqA, bool isPreffixEqB) {
		if (j > n) {
			if (rest == 0) {
				return 1;
			} else {
				
				return 0;
			}
		} 

		if (_f[j][rest][isPreffixEqA][isPreffixEqB] == -1) 
		{
			long long answer = 0;
			int i = j-1;
			if (j%2 == 0) {
				// d
				int ci = d;	
				if (!isPreffixEqA || (isPreffixEqA && a[i] <= ci))
					if (!isPreffixEqB || (isPreffixEqB && ci <= b[i]))
						answer += f(j+1, (rest*10 + ci)%m, isPreffixEqA && a[i] == ci, isPreffixEqB && ci == b[i] );
			} else {
				// 0..9 / d
				for (int ci = 0; ci <= 9; ci++)
					if (ci != d) {
						if (!isPreffixEqA || (isPreffixEqA && a[i] <= ci))
							if (!isPreffixEqB || (isPreffixEqB && ci <= b[i]))
								answer += f(j+1, (rest*10 + ci)%m, isPreffixEqA && a[i] == ci, isPreffixEqB && ci == b[i] );
					}
			}

			_f[j][rest][isPreffixEqA][isPreffixEqB] = answer % MOD;
		}
		return _f[j][rest][isPreffixEqA][isPreffixEqB];
	}

	int solve(int _m, int _d, string _a, string _b) {
		m = _m;
		d = _d;
		a = _a;
		b = _b;
		n = a.size();
		c = _a;
		memset(_f, -1, sizeof _f);
		return f(1, 0, true, true);
	}

	bool dmagic(int a, int d) {
		string s = to_string(a);
		for (int i = 0; i < s.size(); i++) {
			if ((i+1) % 2 == 0) {
				if (s[i]-'0' != d) return false;
			} else {
				if (s[i]-'0' == d) return false;
			}
		}
		return true;
	}

	int solveNaive(int _m, int _d, string _a, string _b) {
		int answer = 0;
		int a = stoi(_a);
		int b = stoi(_b);
		for (int c = a; c <= b; c++) {
			if (c % m == 0 && dmagic(c,_d)) {
				dout(c);
				answer += 1;
			}
		}
		return answer;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios::sync_with_stdio(false);
	int m;
	int d;
	char a[MAX_M],b[MAX_M];

	scanf("%d%d", &m, &d);
	scanf("%s %s", a, b);
	int n = strlen(b);
	string A = string(a);
	string B = string(b);
	for (int i = 0; i < A.size(); i++) {
		A[i] -= '0';
		B[i] -= '0';
	}
	cout << solution::solve(m, d, A, B) << endl;
	//cout << solution::solveNaive(m, d, string(a), string(b)) << endl;
	return 0;
}