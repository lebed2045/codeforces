#include <cstdio>
#include <cstring>
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

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}


const int MAX_N = 1e4+7;
string s;
map<string,int> m;

vector<int> _can(MAX_N, -1);
bool can(int i) {
	if (_can[i] == -1) {
		_can[i] = false;
		assert(i <= s.size());
		// empty
		if (i == s.size()) {
			_can[i] = true;
		} else if (i+1 == s.size()) {
			_can[i] = false;
		} else {
			// 2
			if (i+1 < s.size() && can(i+1 +1)) {
				string suffix({s[i],s[i+1]});
				if (i+1 +2 < s.size()) {
					if (suffix != string({s[i+2],s[i+3]}) || i+1 +3 < s.size()) {
						m[suffix]++;
						_can[i] = true;
					} 
				} else {	
					m[suffix]++;	
					_can[i] = true;
				}
			}
			//3
			if (i+2 < s.size() && can(i+2 +1)) {
				string suffix({s[i],s[i+1],s[i+2]});
				if (i+2 +3 < s.size()) {
					if (suffix != string({s[i+3],s[i+4],s[i+5]}) || i+2 +2 < s.size() ) {
						m[suffix]++;
						_can[i] = true;	
					}
				} else {
					m[suffix]++;
					_can[i] = true;
				}
			}
		}//
	}
	return _can[i];
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i = 5; i < s.size(); i++) {
		can(i);
	}
	/*
	_can.assign(MAX_N, -1);
	s.resize(s.size()-5);
	for(int i = 0; i < s.size(); i++) {
		can(i);
	}
	_can.assign(MAX_N, -1);
	s.resize(s.size()-1);
	for(int i = 0; i < s.size(); i++) {
		can(i);
	}
	_can.assign(MAX_N, -1);
	s.resize(s.size()-1);
	for(int i = 0; i < s.size(); i++) {
		can(i);
	}
	*/
	cout << m.size() << "\n";
	for(auto it:m) {
		cout << it.first << "\n";
	}
	return 0;
}