
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;


string s1,s2;

string lexicographicMinimum(string s) {
	int n = s.length();
	if (n % 2 != 0)
		return s;
	string s1 = lexicographicMinimum(s.substr(0, n/2));
	string s2 = lexicographicMinimum(s.substr(n/2, n));
	if (s1 < s2)
		return s1 + s2;
	else
		return s2 + s1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	cin.sync_with_stdio(false);
	cin >> s1 >> s2;

	cout << (lexicographicMinimum(s1) == lexicographicMinimum(s2) ? "YES": "NO") << endl;

	return 0;
}