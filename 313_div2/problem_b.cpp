#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

vector<int> a(5),b(5);

bool solution(vector<int> a,vector<int> b)
{
	/*
	for(int i = 1; i <= 3; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i = 1; i <= 3; i++)
	{
		printf("%d ",b[i]);
	}
	printf("\nsolution above\n");
	*/
	int A = a[1];
	int B = b[1];
	if( A >= (a[2]+a[3]) && B >= max(b[2],b[3]) ) return true;
	if( A >= max(a[2],a[3]) && B >= (b[2]+b[3]) ) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif

	cin >> a[1] >> b[1];
	cin >> a[2] >> b[2];
	cin >> a[3] >> b[3];

	bool isPossible = false;
	isPossible |= solution(a,b);
	swap(a[2], b[2]);
	isPossible |= solution(a,b);
	swap(a[3], b[3]);
	isPossible |= solution(a,b);
	swap(a[2], b[2]);
	isPossible |= solution(a,b);

	cout << (isPossible ? "YES": "NO") << endl;

	return 0;
}