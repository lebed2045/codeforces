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

const int MAX_N = 1e5+7;
const int INF = 100500;
int n, m;
vector <int> ecolor(MAX_N);
vector < vector<int> > gv(MAX_N), ge(MAX_N);
int right_color;

void solution() {
	vector <int> answer, temp;
	for (right_color: {'R':'B'}) {
		temp = paintMin();
		if (answer.size() == 0 || answer.size() > temp.size()) {
			answer = temp;
		}
	}
	if (answer.size() == 0) {
		cout << "-1\n";
	} else {
		cout << answer.size() << "\n";
		for (int i: answer) {
			cout << i << " ";
		}
	}
}

void readData() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x,y;
		string color;
		cin >> x >> y >> color;
		ecolor[i] = color[0];
		gv[x].push_back(y);
		ge[x].push_back(i);
		gv[y].push_back(x);
		ge[y].push_back(i);
	}
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	readData();
	return 0;
}