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
	// x in [2,100]
	int primes[] = {2, 4, 3, 9, 5, 25, 7, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	
	int divs = 0;
	char c_str[100];
	for (auto div: primes) {
		//cout << div << endl;
		printf("%d\n", div);
		fflush(stdout);
		scanf("%s", c_str);

		if (c_str[0] == 'y') divs++;
	}
	if (divs >= 2) {
		printf("%s\n", "composite");
		//cout << "composite" << endl;
	} else {
		printf("%s\n", "prime");
		//cout << "prime" << endl;
	}
 	return 0;
}