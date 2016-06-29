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
#include <unordered_map>
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

#define ALL(x) (x).begin(), (x).end()
//#define FORN(i,n) for (int i = 0; i < (int)n; i++) BS
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};


const int MAX_N = 500+3;
vi c;
queue<int> q;
priority_queue<int, std::vector<int>, std::greater<int> > pq;
string s;

int n,m,k;

char _f[MAX_N][MAX_N][MAX_N];
bool f(int sum1, int sum2, int i) {
	if (sum1 < 0 || sum2 < 0) 
		return false;
	if (i == n) {
		return sum1 == 0 && sum2 == 0;
	}
	auto& _fi = _f[sum1][sum2][i];
	if (_fi == -1) {
		_fi = f(sum1 - c[i], sum2, i+1) || f(sum1, sum2 - c[i], i+1) || f(sum1,sum2,i+1);
	}
	return _fi;
}

bool canGet(int sum1, int sum2) {
	//_f.clear();
	return f(sum1, sum2, 0);
}

vector<bool> used(MAX_N,false);
void solve() {
	vi answer;
	memset(_f, -1, sizeof _f);
	for (int sum = 0; sum+sum <= k; sum++) {
		if (canGet(sum, k-sum)) {
			used[sum] = used[k-sum] = true;
		}
	}
	for (int sum = 0; sum <= k; sum++) {
		if (used[sum]) {
			answer.pb(sum);
		}
	}
	cout << answer.size() << "\n";
	for (int sum: answer) {
		cout << sum << " ";
	}
}

void readData() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		c.pb(m);
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	solve();
	return 0;
}