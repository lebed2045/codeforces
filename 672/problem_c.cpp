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

typedef pair<int,int> point;

point a,b,t;
int n;
vector < point > vp;

vector <long double> vdA,vdB,vdT;
vector<pair <long double, int> > vA, vB;

long double dist(point &a, point &b) {
	long double dx = a.first - b.first;
	long double dy = a.second - b.second;
	return sqrt( dx * dx + dy * dy );
}

long double maxOpimisation(vector <int> idx) {
	//make unique
	set<int> s;
	for (int i: idx) {
		s.insert(i);
	}
	vector <int> v;
	for (int i: s) {
		v.push_back(i);
	}
	//solution
	long double answer = -1e+12;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				int ii = v[i];
				int jj = v[j];
				long double opt = vdT[ii] - vdA[ii] + vdT[jj] - vdB[jj];
				answer = max(answer,opt);
			}
		}
	}
	return answer;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	scanf("%d%d", &a.first, &a.second);
	scanf("%d%d", &b.first, &b.second);
	scanf("%d%d", &t.first, &t.second);
	scanf("%d", &n);


	long double T = 0.0;
	for (int i = 0; i < n; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		point temp = make_pair(x,y);
		vp.push_back( temp );

		long double dT = dist(t, temp);
		long double dA = dist(a, temp);
		long double dB = dist(b, temp);
		vdT.push_back(dT);
		vdA.push_back(dA);
		vdB.push_back(dB);
		//dout(dB);

		T += dT*2.0;
		vA.push_back( make_pair(dT - dA,i) );
		vB.push_back( make_pair(dT - dB,i) );
	}

	sort( vA.rbegin(), vA.rend() );
	sort( vB.rbegin(), vB.rend() );
	// only A or B
	//dout(vA.size());
	long double maxOpt = max( vA[0].first, vB[0].first );
	//dout(maxOpt);
	// both
	vector <int> vi;
	for (int i = 0; i < n && i < 3; i++) {
		vi.push_back( vA[i].second );
		vi.push_back( vB[i].second );
	}
	maxOpt = max(maxOpt, maxOpimisation(vi));
	cout.precision(17);
	cout << T-maxOpt << endl;


	return 0;
}