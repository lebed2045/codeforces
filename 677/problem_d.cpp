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

const int MAX_N = 3000+7;

typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int n,m, p;
vector < vector<int> > d(MAX_N, vector<int> (MAX_N, -1) );
vector < vector< pii > > l(MAX_N*MAX_N);

int xy2i(int x, int y) {
	return x*m + y;
}

vector <vector <int> > used(MAX_N, vector<int> (MAX_N, -1));
void go1(int i) {
	for (auto& curr: l[i]) {
		int x = curr.first; 
		int y = curr.second;
		for (auto& next: l[i+1]) {
			int xx = next.first;
			int yy = next.second;
			int dist = abs(x - xx) + abs(y - yy);
			if (used[xx][yy] != i || d[xx][yy] > d[x][y]+dist) {
				d[xx][yy] = d[x][y] + dist;
				used[xx][yy] = i;
			}	  
		}
	}
}


const int DX[] = {0, -1, 0, 1};
const int DY[] = {-1, 0, 1, 0};
set<pip> pq;
void go2(int i) {
	for (auto &curr: l[i]) {
		int &x = curr.first; 
		int &y = curr.second;
		pq.insert( pip(d[x][y], curr) );
		/*
		dout(i);
		printf("(%d %d)\n",x,y);
		dout(d[x][y]);	
		*/
		used[x][y] = i;
	}
	//for (int i = 0; i < n; i++) dout(used[i]);
	while (!pq.empty()) {
		auto curr = pq.begin()->second;
		int curr_d = pq.begin()->first + 1;
		//dout(curr_d);
		pq.erase(pq.begin());
		for (int di = 0; di < 4; di++) {
			int xx = curr.first + DX[di];
			int yy = curr.second + DY[di];
			if (0 <= xx && xx < n && 0 <= yy && yy < m && used[xx][yy] != i) {
				used[xx][yy] = i;
				d[xx][yy] = curr_d;
				pq.insert( pip(curr_d, pii(xx,yy)) );
			}
		}
	}
	//for (int i = 0; i < n; i++) dout(d[i]);
}

long long solution() {
	for (int i = 0; i < p; i++) {
		int x = l[i].size();
		int y = l[i+1].size();
		if (x*y <= n*m*10) {
			go1(i);
		} else {
			go2(i);
		}
	}

	assert(l[p].size() == 1);
	return d[ l[p][0].first ][ l[p][0].second ];
}

void readData() {
	l[0].push_back( pii(0,0) );
	d[0][0] = 0;

	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			scanf("%d", &temp);

			l[temp].push_back( pii(i,j) );
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