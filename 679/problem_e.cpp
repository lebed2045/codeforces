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

const int DX[] = {-1, 0, 1, 0, 0};
const int DY[] = { 0, 1, 0,-1, 0};


const int MAX_N = 500+7;



int n, k;
char a[MAX_N][MAX_N];

vector<int> parent(MAX_N*MAX_N);
vector<int> size(MAX_N*MAX_N);
//vector<int> gates(MAX_N*MAX_N);
int gates[MAX_N*MAX_N];
void make_set (int v) {
	parent[v] = v;
	size[v] = 1;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (size[a] < size[b])
			swap (a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

inline int xy2i(int x, int y) {
	return x*MAX_N + y;
}

int addCell(int x,int y) {
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int xx = x + DX[i];
		int yy = y + DY[i];
		//dout(xx);
		//dout(yy);
		if (0 <= xx && xx < n && 0 <= yy && yy < n) {
			if (a[xx][yy] == '.') {
				int s =  find_set(xy2i(xx,yy));
				gates[s]++;
				if (gates[s] == 1) {
					res += size[s];
					//dout(size[s]);
				} 
			}
		}
	}
	return res;
}

int delCell(int x,int y) {
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int xx = x + DX[i];
		int yy = y + DY[i];
		if (0 <= xx && xx < n && 0 <= yy && yy < n) {
			if (a[xx][yy] == '.') {
				int s =  find_set(xy2i(xx,yy));
				gates[s]--;
				if (gates[s] == 0) {
					res += size[s];
				} 
			}
		}
	}
	return res;
}

int solve() {
	int answer = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (a[x][y] == '.') {
				make_set(xy2i(x,y));
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (a[x][y] == '.')
			for (int i = 0; i < 4; i++) {
				int xx = x + DX[i];
				int yy = y + DY[i];
				if (0 <= xx && xx < n && 0 <= yy && yy < n) {
					if (a[xx][yy] == '.') {
						union_sets( xy2i(x,y), xy2i(xx,yy) );	
					}
				}
			}
		}
	}

	//dout(addCell(1,1));
	//return 0;
/*
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (a[x][y] == '.') {
				dout(size[find_set(xy2i(x,y))]);
			}
		}
	}*/


	for (int x = 0; x < n-k+1; x++) {
		memset(gates, 0, sizeof gates);
		int sum = 0;
		int pattern = 0;

		for (int xx = x; xx < x+k; xx++) {
			for (int yy = 0; yy < k; yy++) {
				sum += addCell(xx,yy);
				if (a[xx][yy] == 'X') pattern++;
			}
		}
		//dout(sum);
		//dout(pattern);
		answer = max(answer, sum+pattern);
		for (int y = 0; y < n-k; y++) {
			//rem col
			for (int xx = x; xx < x+k; xx++) {
				sum -= delCell(xx,y);
				if (a[xx][y] == 'X') pattern--;
			}
			//add col
			int yy = y+k;
			for (int xx = x; xx < x+k; xx++) {
				sum += addCell(xx,yy);
				if (a[xx][yy] == 'X') pattern++;
			}
			//cal res
			answer = max(answer, sum+pattern);
			//dout(sum);
			//dout(pattern);
		}
	}
	return answer;
}

void readData() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	printf("%d\n",solve());
	return 0;
}