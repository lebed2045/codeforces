#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (auto vi : v)
		out << vi << ", ";
	out << "]\n";
	return out;
}

string a, b;

map<int,int> strToMap(string a) {
	map<int,int> result;
	for (auto d: a) {
		result[d]++;
	}
	return result;
}

string solution() {
	// find length of number
	int lengthOfN = 9;
	int lengthOflength = 1;
	while (a.length() - lengthOflength > lengthOfN) {
		lengthOfN = lengthOfN*10 + 9;
		lengthOflength += 1;
	}
	lengthOfN = a.length() - lengthOflength;
	stringstream ss;
	string lengthStr;
	ss << lengthOfN; ss >> lengthStr; 
	dout(lengthStr);

	map<int,int> lengthM = strToMap(lengthStr);


	string preffix, suffix;
	// put rest of digits in map
	map<int,int> bM = strToMap(b);
	map<int,int> aM;
	for (auto digit: a) {
		if (lengthM[digit] > 0) {
			lengthM[digit] -= 1;
		} else if (bM[digit] > 0) {
			bM[digit] -= 1;
		} else {
			aM[digit]++;
		}
	}

	// compile answer
	for (int d = '1'; d <= '9'; d++) 
		if (aM[d]) {
			preffix.push_back(d); aM[d]--; break;
		}

	bool bFront = true;
	for(int i = 0; i+1 < b.size(); i++) {
		if (b[i] > b[i+1]) {
			bFront = false;
			break;
		}
	}
		

	for (auto it: aM) {
		int digit = it.first;
		// repeat
		for (int i = 0; i < it.second; i++) {
			if (digit == '0') {
				if (preffix.size() > 0) {

					preffix.push_back(digit);
				} else {
					b.push_back(digit);
				}
			} else if (digit < b[0] || (digit == b[0] && bFront)) {
				preffix.push_back(digit);
			} else {
				b.push_back(digit);
			}
		}
	}
	assert(preffix.size() + b.size() + lengthStr.size() == a.size());
	return preffix + b;
}

int main() {
#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> a >> b;
	cout << solution() << "\n";
	return 0;
}