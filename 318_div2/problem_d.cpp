#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 100000 + 9;
int n;
int h[MAX_N];
int longestPyramidPrefix[MAX_N];
int longestPyramidSuffix[MAX_N];

int solution()
{
	memset(longestPyramidPrefix, 0, sizeof longestPyramidPrefix);
	memset(longestPyramidSuffix, 0, sizeof longestPyramidSuffix);

	int currentHight = 0;
	for (int i = 0; i < n; i++) {
		currentHight = min(currentHight+1, h[i]);
		longestPyramidPrefix[i] = currentHight;
	}
	currentHight = 0;
	for (int i = n-1; i >= 0; i--) {
		currentHight = min(currentHight+1, h[i]);
		longestPyramidSuffix[i] = currentHight;
	}

	int answer = 0;
	for (int i = 0; i < n; i++) 
	{
		answer = max(answer, min(longestPyramidPrefix[i],longestPyramidSuffix[i]));
	}
	return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &h[i]);
	} 

	cout << solution() << endl;

	return 0;
}