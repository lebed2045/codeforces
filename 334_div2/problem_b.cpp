#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;


const int MAX_S = 1e6;
int n, k;
vector<int> s;

bool isValidSize(int boxSize) {
	int smallestAvaliable = 0;
	int largestAvaliable = s.size() - 1;
	// packing
	int numberOfBoxes = 0;
	for (; smallestAvaliable <= largestAvaliable; smallestAvaliable++) {
		if (s[smallestAvaliable] <= boxSize) {
			numberOfBoxes += 1;
			int spaceLeft = boxSize - s[smallestAvaliable];
			// TODO: try to put the biggest avaliable
			if (smallestAvaliable != largestAvaliable && s[largestAvaliable] <= spaceLeft) {
				largestAvaliable -= 1;
			}
		} else return false;
	}
	return numberOfBoxes <= k;
}

int solution() {
	int l = 1;
	int r = MAX_S * 2;
	while (l < r) {
		int m = (l + r) / 2;
		if (isValidSize(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		s.push_back(temp);
	}

	printf("%d", solution());

	return 0;
}