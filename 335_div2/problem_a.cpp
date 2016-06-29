#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

vector <int> have,need;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		have.push_back(temp);
	}
	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		need.push_back(temp);
	}


	int transformed = 0;
	for (int i = 0; i < 3; i++)
		if (have[i] > need[i]) {
			int can_transform = have[i] - need[i];
			int transformed_here = can_transform/2;
			have[i] -= transformed_here*2;
			transformed += transformed_here;
		}
	
	for (int i = 0; i < 3; i++)
		if (need[i] > have[i]) {
			int need_to_transform = need[i] - have[i];
			int put_here = min(need_to_transform,transformed);
			transformed -= put_here;
			have[i] += put_here;
		}

	/*
	for (int t = 0; t < 1000; t++) {
		int transformed = 0;
		for (int i = 0; i < 3; i++) {
			if (have[i] > need[i]) {
				int can_transform = have[i] - need[i];
				int transformed_here = can_transform/2;
				have[i] -= transformed_here*2;
				transformed += transformed_here;

			} else {
				int need_to_transform = need[i] - have[i];
				if (need_to_transform > 0) {
					int put_here = min(need_to_transform,transformed);
					transformed -= put_here;
					have[i] += put_here;
				}
			}
		}
	}
	*/	

	bool is_able = true;
	for (int i = 0; i < 3; i++) {
		//dout(have[i]);
		if (need[i] > have[i]) is_able = false;
	}

	cout << (is_able ? "Yes": "No") << endl;

	return 0;
}