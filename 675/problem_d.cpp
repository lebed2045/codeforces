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
vector <int> a,l,r,p;
struct mybtree {
	int add(int key) {
		if (a.size() == 0) {
			a.push_back(key);
			p.push_back(0);
			l.push_back(0);
			r.push_back(0);	
			return 0;
		}
		
		int curr_node = 0;
		while (true) {
			//dout(curr_node);
			if (a[curr_node] < key) {
				//go right
				if (r[curr_node]) {
					curr_node = r[curr_node];	
				} else {
					r[curr_node] = a.size();
					p.push_back(curr_node);
					break;
				}
			} else {
				if (l[curr_node]) {
					curr_node = l[curr_node];
				} else {
					l[curr_node] = a.size();
					p.push_back(curr_node);
					break;
				}
			}
		}
		a.push_back(key);
		p.push_back(curr_node);
		l.push_back(0);
		r.push_back(0);	
		return a[curr_node];
	}
} tree;


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
		int parent =  tree.add(temp);
		if (i > 0) {
			printf("%d ", parent);
		}
	}
	return 0;
}