
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define dout(x) cout << (#x) << " = " << (x) << endl

typedef long long ll;

//const int MAX_A = 1000000+9;
int n;
vector <int> a;

ll solution() {
	sort(a.begin(), a.end());
	int MAX_A = a[a.size()-1] + 1;
	vector <int> b(MAX_A);
	vector <int> c(MAX_A);

	for (int i = 0; i < n; ++i) {
		b[ a[i] ] += 1;
	}

	printf("\n");

	for (int i = 0; i < MAX_A; ++i) {
		if (b[i] > 0) {
			c[i] += b[i];
			for (int j = i+i; j < MAX_A; j += i) {
				if (b[j] > 0) {
					c[j] = max(c[j], c[i]);
				}
			}

		}
	}

	return *max_element(c.begin(), c.end());
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	cout << solution() << endl;

	return 0;
}
