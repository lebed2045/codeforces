#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 4003;
int n,m;
int a[MAX_N];
bool know[MAX_N][MAX_N];
pair<int,int> e[MAX_N];


int solution()
{
	int m1,m2,m3;
	int answer = -1;
	for (int i = 0; i < m; i++) {
		int recognition = 0;
		m1 = e[i].first;
		m2 = e[i].second;
		recognition = a[m1] - 2 + a[m2] - 2;
		for (m3 = 1; m3 <= n; m3++) 
			if (know[m1][m3] && know[m2][m3]){
				int temp = recognition + a[m3]-2;
				if (answer == -1 || answer > temp) {
					answer = temp;
				}
			}
	}
	return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	scanf("%d%d", &n,&m);
	memset(a, 0, sizeof a);
	memset(know, false, sizeof know);
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		e[i].first = x;
		e[i].second = y;
		a[x] += 1;
		a[y] += 1;
		know[x][y] = know[y][x] = true;
	} 

	cout << solution() << endl;

	return 0;
}