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

int n;
vector <int> a;
typedef pair<int,int> pii;

const int MAX_N = 5000+100;

int count_t[MAX_N];
struct {
	vector <pii> v;
	
	void add(int t) {
		count_t[t]++;
		v.push_back(pii(count_t[t],-t));
		push_heap(v.begin(),v.end());
	}
	int getResult(void) {
		return -v.begin()->second;
	}
	void clear(void) {
		v.clear();
		memset(count_t, 0, sizeof count_t);
	}
} myStruct;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}

	map<int,int> result;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			myStruct.add(a[j]);
			result[ myStruct.getResult() ] += 1;
		}
		myStruct.clear();
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}