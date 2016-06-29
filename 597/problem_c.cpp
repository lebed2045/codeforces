#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

typedef long long ll;

const int MAX_N = 100*1000+9;
const int MAX_K = 12;

int n,k;
int a[MAX_N];

ll _f[MAX_N][MAX_K];
ll solve() {
	memset(_f, 0, sizeof _f);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}