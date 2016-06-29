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

#define dout(x) cout << #x << " = " << x << endl;

const int MOD = 1e9 + 7;
int n, b, k, x;
vector <int> v;

void print_vector(vector <int> & v) {
	cout << "v = ";
	for (auto i: v) {
		cout << i << ",";
	}
	cout <<"\n";
}

struct Integers{
	int length;
	int base;
	vector <int> integers;

	int base_by_mod_x;
	vector <int> integers_by_mod_x;
	vector <long long> number_of_integers_by_mod_x;

	Integers() {
		length = 0;
		base = 10;
		take_by_mod_x();
	}

	Integers(vector <int> v) {
		length = 1;
		base = 10;
		integers = v;
		take_by_mod_x();
	}

	void take_by_mod_x() {
		integers_by_mod_x = vector <int>();
		for (auto integer: integers) {
			integers_by_mod_x.push_back(integer % x);
		}

		base_by_mod_x = base % x;
		number_of_integers_by_mod_x = vector <long long> (x);
		for (auto integer_by_mod_x: integers_by_mod_x) {
			number_of_integers_by_mod_x[integer_by_mod_x] += 1;
		}
	}


	Integers concatinate_all_ways(Integers other) {
		Integers res;
		for (auto preffix: other.integers) {
			for (auto suffix: integers) {
				int integer = preffix * base + suffix;
				res.integers.push_back(integer);
			}
		}
		res.length  = length + other.length;
		res.base = base * other.base;
		res.take_by_mod_x();
		return res;
	}

	Integers concatinate_all_ways2(Integers other) {
		Integers res;
		for (int preffix_by_mod_x = 0; preffix_by_mod_x < x; preffix_by_mod_x++) {
			for (int suffix_by_mod_x = 0; suffix_by_mod_x < x; suffix_by_mod_x++) {
				int integer_by_mod_x = (preffix_by_mod_x * base_by_mod_x + suffix_by_mod_x) % x;
				res.number_of_integers_by_mod_x[integer_by_mod_x] += (number_of_integers_by_mod_x[preffix_by_mod_x] *
																     other.number_of_integers_by_mod_x[suffix_by_mod_x]) % MOD;
			}
		}
		res.length  = length + other.length;
		res.base_by_mod_x = (base_by_mod_x * other.base_by_mod_x) % x;
		return res;
	}


};

int solve() {
	Integers res(v), a(v); b -= 1;

	/*
	for (int i = 1; i <= b; i++) {
		res = res.concatinate_all_ways2(a);
	}
	*/
	
	while (b) {
		if (b%2 == 1) {
			res = res.concatinate_all_ways(a);
			b -= 1;
		}
		b /= 2;
		a = a.concatinate_all_ways(a);
	}
	
	//print_vector(res.integers_by_mod_x);
	return res.number_of_integers_by_mod_x[k];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios::sync_with_stdio(false);
	scanf("%d%d%d%d", &n, &b, &k, &x);
	for (int i = 0; i < n; i++) {
		int ai;
		scanf("%d", &ai);
		v.push_back(ai);
	}
	cout << solve();
	return 0;
}