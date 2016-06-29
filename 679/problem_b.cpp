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
/*
void binarySearch() {
	int L = minValue - 1, R = maxValue + 1;
	while (R - L > 1) {
	    int M = (L + R) / 2;
	    if (check(M)) {
	        R = M;
	    } else {
	        L = M;
	    }
	}
	return {L,R}
}
*/
int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n,k;
	vector<int> a;
	cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		//use bcd
		vector<int> temp;
		if (0 <= k-i) 
			temp.push_back(a[k-i]);
		if(i > 0 && k+i < n) 
			temp.push_back(a[k+i]);
		
		bool allK = true;
		for(auto p: temp) {
			if (p == 0) allK = false;
		}
		if (allK) {
			answer += temp.size();
		}
	}
	cout << answer << "\n";
	return 0;
}