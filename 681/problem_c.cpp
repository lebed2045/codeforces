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
#include <functional>
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
#define FORN(i,n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};

int n;
vector <pii> answer;
vi v;
 std::priority_queue<int, std::vector<int>, std::greater<int> > q;

void solve() {
	printf("%d\n", (int)answer.size());
	for (auto it: answer) {
		if (it.fr == 'i') {
			printf("insert %d\n", it.sc);
		}
		if (it.fr == 'g') {
			printf("getMin %d\n", it.sc);
		}
		if (it.fr == 'r') {
			assert(it.sc == 0);
			printf("removeMin\n");
		}
	}
}


void readData() {
	scanf("%d", &n);
	char s[100];
	FORN(i,n) {
		scanf("%s", s);
		int temp = 0;
		if (s[0] == 'i') {
			scanf("%d", &temp);
			q.push(temp);
		}
		if (s[0] == 'g') {
			scanf("%d", &temp);	
			while (!q.empty() && q.top() < temp) {
				q.pop();
				answer.pb( pii('r',0) );
			}
			if ( !(q.size() > 0 && q.top() == temp) ) {
				q.push(temp);
				answer.pb( pii('i',temp) );
			}				
			assert(q.size() > 0 && q.top() == temp);
		}
		if (s[0] == 'r') {
			if (q.empty()) {
				q.push( temp );
				answer.pb( pii('i',temp) );
			}
			q.pop();
		}
		answer.pb( pii(s[0], temp) );
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