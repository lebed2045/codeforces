#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

int n;
int a[1000000];
map<int,int> a2i;
int b[1000000];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	int max_b = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		a[i] = temp;
		a2i[ temp ] = i;
		b[i] = 1;
		if ( a2i[temp-1] > 0 ) {
			b[i] += b[ a2i[temp-1] ];
		}
		max_b = max(max_b,b[i]);
	}

	cout << n-max_b << endl;

	return 0;
}