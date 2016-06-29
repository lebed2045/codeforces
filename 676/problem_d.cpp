#include <iostream>
#include <sstream>
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

void TL() {while(1){};}

int DX[] = {-1, +0, +1, +0};
int DY[] = {+0, +1, +0, -1};
map <int,string> go = {
{'+',"****"},
{'-',".*.*"},
{'|',"*.*."},
{'^',"*..."},
{'>',".*.."},
{'v',"..*."},
{'<',"...*"},
{'U',".***"},
{'R',"*.**"},
{'D',"**.*"},
{'L',"***."},
{'*',"...."}
};
map <int,int> m_rotate = {
{'+','+'},
{'-','|'},
{'|','-'},
{'^','>'},
{'>','v'},
{'<','^'},
{'v','<'},
{'L','U'},
{'R','D'},
{'U','R'},
{'D','L'},
{'*','*'}
};
const int MAX_N = 1000+9;


int n,m;
vector< vector <string> > s(4, vector<string>(MAX_N));
int tx, ty;
int mx, my;
vector< vector<int> > g(MAX_N*MAX_N*4);
vector<int> d(MAX_N*MAX_N*4);

int xyl2v(int x, int y, int l) {
	return x*m + y + n*m*l;
}

string v2xyl(int v) {
	int l = v/(n*m);
	int x = (v%(n*m))/m;
	int y = v - x*m - l*m*n;
	stringstream ss; ss << "(" << x << "," << y << "," << l <<")";
	string s; ss >> s;
	return s;
}

void addEdge( int v1, int v2 ) {
	g[v1].push_back(v2);
	g[v2].push_back(v1);
}

vector <int> nextVerteces(int v) {
	vector<int> answer;
	int l = v/(n*m);
	int x = (v%(n*m))/m;
	int y = v - x*m - l*m*n;
	assert(0 <= x && x < n);
	assert(0 <= y && y < m);
	assert(0 <= l && l < 4);
	answer.push_back( xyl2v(x,y,(l+1)%4) );
	string str = go[ s[l][x][y] ];
	assert(str.size() == 4);
	for (int i = 0; i < 4; i++)
		if (str[i] == '*') {
			int xx = x + DX[i];
			int yy = y + DY[i];
			if (0 <= xx && xx < n && 0 <= yy && yy < m) {
				string str2 = go[ s[l][xx][yy] ];
				assert(str2.size() == 4);
				if (str2[(i+2)%4] == '*') {
					answer.push_back( xyl2v(xx,yy,l) );
					//printf("(%d,%d) - (%d,%d)\n",x,y,xx,yy);
				}
			}
		}
	return answer;	
}

//set< pair<int,int> > pq;
queue<int> q;
void bfs(int v) {
	fill(d.begin(), d.end(), -1);
	d[v] = 0; q.push(v);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (auto& next: nextVerteces(curr)) {
			//assert(next < d.size());
			if (d[next] == -1) {
				d[next] = d[curr] + 1;
				q.push( next );
				//cerr  << q.size() << "\n";
			}
		}
	}
}

void solve() {

	for (int l = 0; l < 3; l++) {
		//printf("l = %d\n", l);
		/*
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				// go 4 dir
				string str = go[ s[x][y] ];
				assert(str.size() == 4);
				for (int i = 0; i < 4; i++)
					if (str[i] == '*') {
						int xx = x + DX[i];
						int yy = y + DY[i];
						if (0 <= xx && xx < n && 0 <= yy && yy < m) {
							string str2 = go[ s[xx][yy] ];
							assert(str2.size() == 4);
							if (str2[(i+2)%4] == '*') {
								//addEdge( xyl2v(x,y,l), xyl2v(xx,yy,l) );
								//printf("(%d,%d) - (%d,%d)\n",x,y,xx,yy);
							}
						}
					}
				// roate
				//addEdge( xyl2v(x,y,l), xyl2v(x,y,(l+1)%4) );
				g[ xyl2v(x,y,l) ].push_back( xyl2v(x,y,(l+1)%4) );
			}
		*/
		// rotate
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				s[l+1][x][y] = m_rotate[ s[l][x][y] ];
				//cerr << s[x][y];
			}
			//cerr << "\n";
		}
	}
	
	bfs( xyl2v(tx,ty,0) ); 
	
	int answer = -1;
	int answer_v = -1;
	for (int l = 0; l < 4; l++) {
		int temp = d[ xyl2v(mx, my, l) ];
		int temp_v = xyl2v(mx, my, l);
		//dout(temp);
		if ( temp != -1) {
			if (answer == -1) {
				answer = temp; 
				answer_v = temp_v;
			} else {
				//answer = min(answer, temp);	
				if (temp < answer) {
					answer = temp;
					answer_v = temp_v;
				}
			}
		}
	}
	cout << answer << endl;
}


void readData() {
	char cstr[MAX_N];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", cstr);
		s[0][i] = string(cstr);
		s[1][i] = string(cstr);
		s[2][i] = string(cstr);
		s[3][i] = string(cstr);
	}
	scanf("%d%d", &tx, &ty);
	tx -= 1;
	ty -= 1;
	scanf("%d%d", &mx, &my);
	mx -= 1;
	my -= 1;
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