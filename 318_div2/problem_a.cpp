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
	int limark = a[0];
	for (int i = 1; i < n; i++) {
		m[a[i]] += 1;
	}

	int bestCompetetor = -1;
	while ( (bestCompetetor = m.rbegin()->first) >= limark ) {
		//bribe vote
		limark += 1;
		m[bestCompetetor] -= 1;
		if (m[bestCompetetor] == 0) {
			m.erase(bestCompetetor);
		}
		m[bestCompetetor-1] += 1;
	}

	return limark - a[0];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	} 

	cout << solution() << endl;

	return 0;
}