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
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;
#define ALL(x) (x).begin(), (x).end()
typedef pair <int,int> pii;

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

const int MAX_N = 1024;
const int MOD = 1e9+7;

struct RSQ {
	static const int len = 1024;
	vector <double> a = vector<double>(len*2+1, 0.0);
	
	void add(int i, double value, int node = 1, int l = 0, int r = len-1) {
		if (l <= i && i <= r) {
			a[node] += value;
			if (l < r) {
				int m = (l+r) / 2;
				add(i, value, node*2, l, m);
				add(i, value, node*2+1, m+1, r);	
			}
		}
	}

	double sum(int ql, int qr, int node = 1, int l = 0, int r = len-1) {
		if (ql <= l && r <= qr) {
			return a[node];
		} else 
		if (qr < l || r < ql) {
			return 0; 
		} else {
			int m = (l+r) / 2;
			return sum(ql, qr, node*2, l, m) + sum(ql, qr, node*2+1, m+1, r);
		}
	}
};

int n;
vector < vector <int> > a(MAX_N, vector <int> (MAX_N));

vector < vector< vector<int> > > _len2zero(MAX_N, vector< vector<int> >(MAX_N, vector<int>(8, -1)));
const int DX[] = {-1, -1,  0, +1, +1, +1,  0, -1};
const int DY[] = { 0, +1, +1, +1,  0, -1, -1, -1};
int len2zero(int x,int y, int dir) {
	if (!(0 <= x && x < n && 0 <= y && y < n) || a[x][y] == 0) {
		return 0;
	}
	int &res = _len2zero[x][y][dir];
	if (res == -1) {
		res = 1 + len2zero(x + DX[dir], y + DY[dir], dir);
	}
	return res;
}

unordered_map<int,RSQ> sumLine, sumColumn, sumMainD, sumMinorD;

long long solution() {
	//calc part sums
	vector <double> ln({-1, log(1.0), log(2.0), log(3.0)});
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			sumLine[x].add(y, ln[a[x][y]]);
			sumColumn[y].add(x, ln[a[x][y]]);
			sumMainD[n+x-y].add(x, ln[a[x][y]]);
			sumMinorD[x+y].add(x, ln[a[x][y]]);
		}
	}
	// calc max
	tuple <double, int,int,int, bool> best;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			// normal cross
			int d = 100500; 
			for(int dir: {0,2,4,6}) {
				d = min(d, len2zero(x,y,dir));
			}
			if(d) d--;
			double logSum = sumLine[x].sum(y-d,y+d) + sumColumn[y].sum(x-d,x+d) - ln[a[x][y]];
			
			//fprintf(stderr,"(%d%d) , nd = %d, lns = %f\n",x,y,d, logSum);
			if (logSum > get<0>(best)) {
				best = make_tuple(logSum, x, y, d, true);
			}

			//rotate cross
			d = 100500;
			for (int dir: {1,3,5,7}) {
				d = min(d, len2zero(x,y,dir));
			}
			if(d) d--;
			logSum = sumMainD[n+x-y].sum(x-d,x+d) + sumMinorD[x+y].sum(x-d,x+d) - ln[a[x][y]];

			//printf("(%d%d) , rd = %d, lns = %f\n",x,y,d, logSum);
			if (logSum > get<0>(best)) {
				best = make_tuple(logSum, x, y, d, false);
			}
		}
	}
	// cal res
	double temp;
	int x,y,d;
	bool isNormal;
	tie(temp, x,y,d, isNormal) = best;
	long long result = a[x][y];
	if ( isNormal ) {
		for (int dd = 1; dd <= d; dd++) {
			for (int dir: {0,2,4,6}) {
				result *= a[ x + DX[dir]*dd ][ y + DY[dir]*dd ];
				result %= MOD;
			}
		}
	} else {
		for (int dd = 1; dd <= d; dd++) {
			for (int dir: {1,3,5,7}) {
				result *= a[ x + DX[dir]*dd ][ y + DY[dir]*dd ];
				result %= MOD;
			}
		}
	}
	return result;
}

void readData() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		assert(s.size() == n);
		for (int j = 0; j < (int)s.size(); j++) {
			a[i][j] = s[j]-'0';
		}
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	cout << solution() << "\n";
	return 0;
}