#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
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

const int MAX_N = 1000+7;
//const int DX[] = {-1, 0, 1, 0, 0};
//const int DY[] = { 0, 1, 0,-1, 0};
const int DX[] = { 0, +1,  0, -1, 0};
const int DY[] = {-1,  0, +1,  0, 0};
map<int,int> char2Bitmask = {
	{'+',0b1111},
	{'-',0b0101},
	{'|',0b1010},
	{'^',0b1000},
	{'>',0b0100},
	{'v',0b0010},
	{'<',0b0001},

	{'U',0b0111},
	{'R',0b1011},
	{'D',0b1101},
	{'L',0b1110},
	{'*',0b0000},
};

int n,m;
vector< vector < vector<int> > > g(4, vector< vector<int> >( MAX_N, vector<int>(MAX_N, 0) ));
vector< vector < vector<int> > > d(4, vector< vector<int> >( MAX_N, vector<int>(MAX_N, -1) ));


struct Vertex {
	int x,y,l;
 	Vertex(){}
 	Vertex(int _l, int _x,int _y) {
 		l = _l;
 		x = _x;
 		y = _y;
 	}
 	bool isOnBoard() {
 		return 0 <= x && x < n && 0 <= y && y < m;
 	}
 	bool hasDoor(int direction) {
 		return g[l][x][y] & (1<<direction);
 	}
 }; 

Vertex start,finish;
int rotateBitmask(int mask) {
	return ((mask>>1) | (mask<<3))&(0b1111);
}

queue<Vertex> q;
int solution() {
	q.push( start );
	d[start.l][start.x][start.y] = 0;
	//p[start.l][start.x][start.y] = start;
	while (!q.empty()) {
		Vertex curr = q.front(); q.pop();
		// go or press
		for (int i = 0; i < 5; i++) {
			if (i == 4 || curr.hasDoor(i) ) {
				Vertex next( (curr.l + (i == 4))%4, curr.x + DX[i], curr.y + DY[i] );
				if (i == 4 || (next.isOnBoard() && next.hasDoor((i+2)%4) ) ) {
					if (d[next.l][next.x][next.y] == -1) {
						d[next.l][next.x][next.y] = d[curr.l][curr.x][curr.y] + 1;
						//p[next.l][next.x][next.y] = curr;
						q.push(next);
					}
				}
			}
		}
	}
	//find solution
	int answer = -1;

	for (int l = 0; l < 4; l++) {
		//dout(d[l][start.x][start.y]);
		//dout(d[l][finish.x][finish.y]);
		if (answer == -1 || answer > d[l][finish.x][finish.y] ) {
			answer = d[l][finish.x][finish.y];
			finish.l = l;
		}
	}
	/*
	do {
		printf("(%d, %d,%d), bitmask = %d\n", finish.l, finish.x, finish.y, g[finish.l][finish.x][finish.y]);
		finish = p[finish.l][finish.x][finish.y];
	} while (finish.l != start.l || finish.x != start.x || finish.y != start.y);
	printf("(%d, %d,%d), bitmask = %d\n", finish.l, finish.x, finish.y, g[finish.l][finish.x][finish.y]);
	*/
	return answer;
}

void readData() {
	char c_str[MAX_N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", c_str);
		for (int j = 0; j < m; j++) {
			g[0][i][j] = char2Bitmask[c_str[j]];
			for (int l = 1; l < 4; l++) {
				g[l][i][j] = rotateBitmask(g[l-1][i][j]);
			}
		}
	}
	scanf("%d%d", &start.x, &start.y); 
	start.x -= 1;
	start.y -= 1;
	start.l = 0;
	scanf("%d%d", &finish.x, &finish.y); 
	finish.x -= 1;
	finish.y -= 1;
	finish.l = -1;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	printf("%d\n", solution());
	return 0;
}