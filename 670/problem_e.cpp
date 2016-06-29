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
#include <list>
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

int n, m, p;
string s,c;
list<int> l;
auto curr = l.begin();

void left(list<int>::iterator &it) {
	if (it != l.begin()) it--;
}

void right(list<int>::iterator &it) {
	it++;
	if (it == l.end()) it--;
}

void eraseSubstr(list<int>::iterator begin, list<int>::iterator end, list<int>::iterator& curr) {
	// erase [curr curr_end]
	// can't remove all substring
	//end++;
	if (++end != l.end()  || begin != l.begin()) {
		curr = end; 
		l.erase(begin,end);	
		if (curr == l.end()) curr--;
	}
}

void printCurr() {
	printf("printCurr = ");
	for (auto it = l.begin(); it != l.end(); it++) {
		if (it != curr) { 
			printf("%c", *it);
		} else {
			printf("%c", (*it == '(' ? '[' : ']') );
		}
	}
	printf("\n");
}

void solve() {
	for(int i = 0; i < n; i++) {
		l.push_back(s[i]);
		if (i+1 == p) curr = --l.end();
	}
	for(auto& command: c) {
		//printCurr();
		if (command == 'L') {
			left(curr);
		}
		if (command == 'R') {
			right(curr);
		}
		if (command == 'D') {
			if (*curr == '(') {
				auto curr_end = curr;
				int sum = 1;
				while (sum > 0) {
					curr_end++;
					sum += (*curr_end == '(' ? +1 : -1);
				}
				eraseSubstr(curr, curr_end, curr);
			} else {
				auto curr_begin = curr;
				int sum = -1;
				while (sum < 0) {
					curr_begin--;
					sum += (*curr_begin == '(' ? +1 : -1);
				}
				eraseSubstr(curr_begin, curr, curr);
			}
		} 
	}
	//printCurr();
}

void writeAnswer() {
	s = "";
	for(auto& it: l) {
		s.push_back(it);
	}
	cout << s << "\n";
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	cin >> s >> c;
	solve();
	writeAnswer();
	return 0;
}