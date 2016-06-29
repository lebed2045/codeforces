#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

int n;
vector<string> vs;

int solve(string setofcharacters) {
	map<int,int> m;
	for (int i = 0; i < (int)setofcharacters.length(); i++) {
		m[ setofcharacters[i] ] = 1;
	}
	//dout(m.size());
	if (m.size() > 2)
		return 0;

	int answer = 0;
	for (int i = 0; i < (int)vs.size(); i++) {
		string word = vs[i];

		bool b = true;
		for (int j = 0; j < (int)word.size(); j++) {
			if (m[word[j]] != 1) {
				b = false;
				break;
			}
		}
		if (b) answer += word.size();

	}
	//dout(answer);
	return answer;
}

int solution() {
	int answer = 0;
	for (int i = 0; i < (int)vs.size(); i++) {
		int temp = solve(vs[i]);
		if (temp > answer)
			answer = temp;
	}
	return answer;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	for(int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vs.push_back(temp);
	}

	cout << solution() << endl;

	return 0;
}