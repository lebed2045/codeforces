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

const int MAX_N = 250;

int n;
string s;
map <int,int> m;
bool was[MAX_N][MAX_N][MAX_N];
bool can[MAX_N][MAX_N][MAX_N];

void dfs(int b, int g, int r) {
	if (was[b][g][r]) return;

	was[b][g][r] = can[b][g][r] = true;
	if (b > 0 && g > 0) dfs(b-1,g-1,r+1);
	if (g > 0 && r > 0) dfs(b+1,g-1,r-1);	
	if (b > 0 && r > 0) dfs(b-1,g+1,r-1);
	if (b > 1) dfs(b-1,g,r);
	if (g > 1) dfs(b,g-1,r);
	if (r > 1) dfs(b,g,r-1);
}

string solution() {
	string answer = "";
	memset(was, false, sizeof was);
	memset(can, false, sizeof can);

	for (int i = 0; i < n; i++) {
		m[ s[i] ]++;
	}
	dfs(m['B'], m['G'], m['R']);
	
	if (can[1][0][0]) answer += "B";
	if (can[0][1][0]) answer += "G";
	if (can[0][0][1]) answer += "R";
	
	return answer;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	cout << solution();
	return 0;
}