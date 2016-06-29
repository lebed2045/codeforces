#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
T nextInt() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}

const int maxN = (int)1e6 + 10;
const int maxL = 17;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const ll LLINF = (ll)1e18;

vector <int> a(10);
vector <int> b(10);
char s[maxN];
char t[maxN];

string get(const vector<int>&cnt) {
    string ret = "";
    for (int i = 0; i < 10; ++i) {
        ret += string(cnt[i], char('0' + i));
    }
    return ret;
}

int main() {

    freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    gets(s);
    gets(t);

    if (strcmp(s, "01") == 0 || strcmp(s, "10") == 0) {
        puts("0");
        return 0;
    }

    int n = strlen(s);
    int m = strlen(t);

    for (int i = 0; i < n; ++i) {
        a[s[i] - '0']++;
    }
    for (int i =0 ; i < m; ++i) {
        b[t[i] - '0']++;
    }

    string T = (const char *) t;

    for (int len = 1; ; ++len) {
        vector <int> cnt = a;
        int tmp = len;
        int c = 0;
        while(tmp > 0) {
            cnt[tmp % 10]--;
            tmp /= 10;
            c++;
        }
        bool ok = true;
        for (int i = 0; i < 10; ++i) {
            cnt[i] -= b[i];
            if (cnt[i] < 0) ok = false;
        }
        if (ok && (t[0] != '0' || *max_element(cnt.begin() + 1, cnt.end())) > 0 && n - c == len) {

        } else continue;
        bool have = false;
        string best = "";
        {
            string cur = T + get(cnt);
            if (cur[0] != '0') {
                if (!have || best > cur) {
                    best = cur;
                    have = true;
                }
            }
        }
        string cur = "";
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] > 0) {
                cur += char(i + '0');
                cnt[i]--;
                break;
            }
        }
        for (int i = 0; i <= 10; ++i) {
            string now = cur + T + get(cnt);

            if (now[0] != '0') {
                if (!have || best > now) {
                    best = now;
                    have = true;
                }
            }
            if (i != 10) {
                cur += string(cnt[i], char(i + '0'));
                cnt[i] = 0;
            }
        }
        assert(have);
     //   cout << len << '\n';
        puts(best.c_str());
        exit(0);
    }

    return 0;
}