#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 100000 + 9;
int n;
int a[MAX_N];

int solution()
{
	for (int i = 0; i < n; i++) {
		while (a[i] % 2 == 0) {
			a[i] /= 2;
		}
		while (a[i] % 3 == 0) {
			a[i] /= 3;
		}
	}

	for (int i = 0; i+1 < n; i++) {
		if (a[i] != a[i+1])
			return false;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	} 

	cout << (solution() ? "Yes" : "No") << endl;

	return 0;
}