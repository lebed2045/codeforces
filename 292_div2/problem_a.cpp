#include <iostream>
#include <string>
using namespace std;

string s,t,a;

int main() {
	cin >> s >> t;
	bool no = false;
	if ( s.length() != t.length() ) {
		no = true;
	} else
	for (int i = 0; i < (int)s.length(); i++) {
		int ss = s[i] - 'a' + 1;
		int tt = t[i] - 'a' + 1;
		
			a += 'a' + (ss+tt)/2;
		}
	}

	if( no ) {
		cout << "No such string";
	} else
	{
		cout << a;
	}
	return 0;
}