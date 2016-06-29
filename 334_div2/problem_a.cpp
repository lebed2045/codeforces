#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
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
	/*The first line of the input contains five space-separated
	integers m1, m2, m3, m4, m5, where mi (0 ≤ mi ≤ 119) is the 
	time of Kevin's last submission for problem i. His last submission is always correct and gets accepted.

	The second line contains five space-separated
	integers w1, w2, w3, w4, w5, where wi (0 ≤ wi ≤ 10) is Kevin's number of wrong submissions on problem i.

	The last line contains two space-separated
	integers hs and hu (0 ≤ hs, hu ≤ 20), denoting the Kevin's numbers of successful and unsuccessful hacks, respectively.
	*/
	vector <double> m(5), w(5);
	for (int i = 0; i < 5; i++) {
		cin >> m[i];
		//dout(m[i]);
	}
	for (int i = 0; i < 5; i++) {
		cin >> w[i];
	}
	int hs, hu;
	cin >> hs >> hu;

	vector<double> x = {500, 1000, 1500, 2000, 2500};
	double score = 0;
	for (int i = 0; i < 5; i++) {
		score += max(0.3 * x[i], (1 - m[i] / 250.0) * x[i] - 50 * w[i]);
	}
	score += hs * 100.0 - hu * 50;
	cout << score << "\n";
	return 0;
}





















