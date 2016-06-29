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


int n;

long long solution(vector <int> &v) {
	long long answer = 0;
	map <int,int> m;
	for (auto vi: v) {
		m[vi]++;
	}
	for (auto it: m) {
		if (it.second > 1) {
			answer += it.second*(it.second-1)/2;
		}
	}
	return answer;
}

void print_vector(vector <int> & v) {
	cout << "v = ";
	for (auto i: v) {
		cout << i << ",";
	}
	cout <<"\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	vector <int> a,b;
	for (int i = 0; i < n; i++) {
		int x,y;
		scanf("%d%d", &x,&y);
		a.push_back(x-y);
		b.push_back(x - (n-y+1) );
	}
	//print_vector(a);
	//print_vector(b);
	cout << solution(a) + solution(b);
	return 0;
}