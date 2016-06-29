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


const int MAX_N = 10000+7;
int n;
string s;
map<string,int> answer;

vector< vector<int> > _f(4, vector<int>(MAX_N, -1));
bool f(int len, int i) {
	int &result = _f[len][i];
	if (result == -1) {
		if (i+len == n) {
			result =  true;
		} else
		if (i+len > n) {
			result = false;
		} else
		if (len == 2) {
			result = f(3, i+2) || 
					(f(2, i+2) && (s[i] != s[i+2] || s[i+1] != s[i+3]));
		} else
		if (len == 3) {
			result = f(2, i+3) || 
					(f(3, i+3) && (s[i] != s[i+3] || s[i+1] != s[i+4] || s[i+2] != s[i+5]));
		}	
		if (result) {
			if (len == 2) {
				answer[ string({s[i],s[i+1]}) ]++;
			} else {
				answer[ string({s[i],s[i+1],s[i+2]}) ]++;
			}
			
		}
	}
	return result;
}

void solve() {
	n = s.size();
	for(int i = 5; i < n; i++) {
		f(2,i);
		f(3,i);
	}
	cout << answer.size() << "\n";
	for(auto& it: answer) {
		cout << it.first << "\n";
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> s;
	solve();
	return 0;
}