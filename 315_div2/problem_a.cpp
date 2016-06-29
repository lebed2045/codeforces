#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 1003;
int n,a[MAX_N];
map<int,int> m;

int solution()
{
	if(m[1] == 0) return 1;
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[n];
		m[a[n]] = 1;	
	} 

	cout << solution();

	return 0;
}