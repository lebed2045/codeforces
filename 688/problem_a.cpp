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

vi v;
queue<int> q;
priority_queue<int, std::vector<int>, std::greater<int> > pq;
const int MAX_N = 1000;
string s[MAX_N];

int n,m,d,k;


void solve() {

}

void readData() {
	cin >> n >> d;
	string full;
	for (int i = 0; i < n; i++) full.pb('1');

	int len = 0;
	int result = 0;
	for (int i = 0; i < d; i++) {
		cin >> s[i];
		if (s[i] != full) {
			len++;
		} else {
			len = 0;
		}
		result = max(result, len);
	}
	cout << result << "\n";
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