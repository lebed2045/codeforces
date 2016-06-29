#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int numberOfTriagles(vector<int> a) {
	return (a[1] + a[2])*(a[2]+a[3])*2 - (a[2]*a[2]) - (a[5]*a[5]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	vector<int> a;

	for(int i = 0; i < 6; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	cout << numberOfTriagles(a) << endl;

	return 0;
}