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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	int k;
	scanf("%d", &k);
	vector <int> s;

	for (int i = 1; i <= k; i++ ) {
		s.push_back(1);
		while (s.size() >= 2 && s[s.size()-1] == s[s.size()-2]) {
			s[s.size()-2] += 1;
			s.pop_back();
		}
	}

	for (int i = 0; i < s.size(); i++) {
		printf("%d ", s[i]);
	}


	return 0;
}