#include <cstdio>
#include <cstring>
#define M_PI 3.14159265359
#include <cmath>
#include <cassert>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;
#define ALL(x) (x).begin(), (x).end()

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    for (auto vi : v)
        out << vi << ", ";
    out << "]\n";
    return out;
}
/*
void binarySearch() {
    int L = minValue - 1, R = maxValue + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    return {L,R}
}
*/

#define ALL(x) (x).begin(), (x).end()
#define FORN(i,n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector <int> vi;
int DX[] = {  0, +1,  0, -1,  0};
int DY[] = {  +1, 0, -1,  0,  0};
template <typename T>
void func(T &t) 
{
    cin >> t;
}

template<typename T, typename... Args>
void func(T &t, Args... &args) // recursive variadic function
{
    cin >> t;

    func(args...) ;
}


int n,m,k,q,t;


void solve() {

}

void readData() {
    int n = 2,m = 5;
    func(n,m);
    cout  << n << " " << m;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    readData();
    solve();
    return 0;
}