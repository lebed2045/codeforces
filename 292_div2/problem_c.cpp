//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define do(x) cerr << #x << " = " << x << endl;

const int MAX_N = 1e5*2 + 10;
int n, m;
int d[MAX_N];
int h[MAX_N];
int ai, bi;
long long sumD[MAX_N];
int jumpL[MAX_N];
int jumpR[MAX_N];
long long _moveL[MAX_N];
long long _moveR[MAX_N];

long long dist(int x, int y) {
	/*
	long long res = 0;
	for (int i = x; i < y; i++) 
		res += d[i];
	return res;
	*/
	return sumD[y-1] - sumD[x-1];
}

long long energy(int x, int y) {
	return 2*(h[x] + h[y]) + dist(x,y);
}

long long moveL(int l, int r, int& newL) {
	if (jumpL[l] != -1 && jumpL[l] < r) {
		newL = jumpL[l];
		return _moveL[l];
	}
	long long hh = h[l]*2;
	long long dd = 0;

	for (int i = l+1; i < r; i++) {
		dd -= d[i-1];

		if( hh < (h[i]*2 + dd) ) {
			newL = i;
			jumpL[l] = i;
			_moveL[l] = h[i]*2+dd - hh;
			return h[i]*2+dd - hh;
		}
	}
	return 0;
}

long long moveR(int l, int r, int& newR) {
	if (jumpR[r] != -1 && l < jumpL[r]) {
		newR = jumpR[r];
		return _moveR[r];
	}
	long long hh = h[r]*2;
	long long dd = 0;

	for (int j = r - 1; l < j; j--) {
		dd -= d[j];

		if( hh < (h[j]*2 + dd) ) {
			newR = j;
			jumpR[r] = j;
			_moveR[r] = h[j]*2 + dd - hh;
			return h[j]*2 + dd - hh;
		}
	}
	return 0;
}

long long maxEnergy(int l, int r) {
	//naive
	/*
	long long _energy = 0;
	for (int i = l; i < r; i++)
		for (int j = i+1; j <= r; j++)
			if( energy(i,j) > _energy ) {
				_energy = energy(i,j);
				//do(i);do(j); do(_energy);
			}
	*/
	// l -> opt <- r
	do {
		int ll, rr;
		long long ml = moveL(l, r, ll);
		long long mr = moveR(l, r, rr);
		if( ml > mr ) {
			l = ll;
		} else
		if( ml < mr ) {
			r = rr;
		} else
		{
			break;
		}
	} while (true);

	return energy(l,r);
}

long long solve() {
	int l, r;
	if ( ai <= bi ) {
		l = bi + 1;
		r = n + ai - 1;
	} else {
		l = bi + 1;
		r = ai - 1;
	}
	//do(l);
	//do(r);
	return maxEnergy(l,r);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	memset(jumpL, -1, sizeof jumpL);
	memset(jumpR, -1, sizeof jumpR);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		d[n+i] = d[i];
	}
	sumD[0] = 0;
	for (int i = 1; i <= n*2; i++) {
		sumD[i] = sumD[i-1] + d[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
		h[n+i] = h[i];
	}

   	std::cout.sync_with_stdio(false);	
	for (int i = 0; i < m; i++) {
		scanf( "%d%d", &ai, &bi);
		cout << solve() << endl;
	}
	

	return 0;
}