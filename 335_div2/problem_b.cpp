#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

typedef pair<int,int> pii;

const int MAX_N = 600;
int x,y,x0,y0;
string s;
int a[MAX_N][MAX_N];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	cin >> x >> y >> x0 >> y0;
	getline(cin, s);
	getline(cin, s);

	for (int x = 0; x < MAX_N; x++) {
		for (int y = 0; y < MAX_N; y++) 
			a[x][y] = -1;
	}

	pii curr = pii(x0,y0),curr2;	
	int answer[s.length()+1];
	for (int k = 0; k <= s.length(); k++) {
		answer[k] = 0;
		if (1 <= curr.first && curr.first <= x)
			if (1 <= curr.second && curr.second <= y) {
				if (a[curr.first][curr.second] == -1) 
					a[curr.first][curr.second] = k;
		}

		int curr_direction = s[k];
		//printf("(%d,%d)->",curr.first,curr.second);

		if (curr_direction == 'U') curr2 = pii(curr.first-1, curr.second);
		if (curr_direction == 'D') curr2 = pii(curr.first+1, curr.second);
		if (curr_direction == 'L') curr2 = pii(curr.first, curr.second-1);
		if (curr_direction == 'R') curr2 = pii(curr.first, curr.second+1);
				if (1 <= curr2.first && curr2.first <= x)
			if (1 <= curr2.second && curr2.second <= y) curr = curr2;
	}

	int last = 0;
	for (int xx = 1; xx <= x; xx++) {
		for (int yy = 1; yy <= y; yy++) {
			//printf("%02d ",a[xx][yy]);
			int temp = a[xx][yy];
			if (temp >= 0) {
				answer[temp] += 1;
			} else last++;
		}
		//printf("\n");
	}
	answer[s.length()] += last;

	for (int k = 0; k <= (int)s.length(); k++) {
		printf("%d ",answer[k]);
	}
	return 0;
}