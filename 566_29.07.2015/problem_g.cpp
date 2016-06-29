
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define dout(x) cout << (#x) << " = " << (x) << endl

typedef long long ll;



/**
ex: 
	std::vector <int> a = {3,7,2,5,6,4,9};
	rmq = RMQ<int>(a);
	a.getMininum() 
*/
template<class T>
class RMQ
{
	public:
		int size;
		std::vector <T> treeMax;
		RMQ() {size = 0;}
		RMQ(std::vector<T>& a) {
			size = a.size();
			treeMax.assign(size * 4, 0);
			buildSegmentTree(a, 1, 0, size-1);
		}

		void buildSegmentTree(const vector<T>& a, int node, int leftBorder, int rightBorder) {
			if (leftBorder == rightBorder)
				treeMax[node] = a[leftBorder];
			else {
				int middle = (leftBorder + rightBorder)/2;
				buildSegmentTree(a, node*2,    leftBorder, middle);
				buildSegmentTree(a, node*2 + 1, middle+1,  rightBorder);
				treeMax[node] = max( treeMax[node*2], treeMax[node*2 + 1] );
			}
		}

		T getMax(int l, int r) {
			return getMaxOnRange(l, r, 1, 0, size-1);
		}

		T getMaxOnRange(int l, int r, int node, int leftBorder, int rightBorder) {
			//cout << "RMQ.getMaxOnRange(" << leftBorder << "," << rightBorder << ")\n";
			if (l > r)
				return 0;
			if (l <= leftBorder && rightBorder <= r)
				return treeMax[node];
			int middle = (leftBorder + rightBorder)/2;
			return max( getMaxOnRange(l, min(r, middle), node*2, leftBorder, middle), 
				        getMaxOnRange(max(l, middle+1), r, node*2 +1, middle+1, rightBorder) );
		}
};

//const int MAX_N = 200000+9;
int n, m;
int x, y;
typedef vector< pair<int,int> > vpii;
vpii a, b, c, d;
RMQ <int> rmq;


bool isAbleToReach(vpii& v, int x, int y) {
	int minL = 0;
	int maxL = v.size()-1;
	int L;

	while (minL < maxL) {
    	L = (minL + maxL) / 2;

      	if (v[L].first < x)
        	minL = L + 1;
      	else
        	maxL = L;
    }

    int maxX = v[maxL].first;
    int maxY = rmq.getMax(minL,v.size()-1);
    return maxX >= x && maxY >= y;
}


bool isAbleToReachLevel(vpii& v, int level) {
	for (int i = 0; i < (int)v.size(); i++) {
			if ( isAbleToReach(v, level - v[i].first, level - v[i].second) ) 
				return true;
	}
	return false;
}

bool isAbleToReachLevelN_2(vpii& v, int level) {
	for (int i = 0; i < (int)v.size(); ++i)
		for (int j = 0; j < (int)v.size(); ++j) {
			int x = v[i].first + v[j].first;
			int y = v[i].second + v[j].second;
			if (x >= level && y >= level) return true;
		}
	return false;
}

int maxLevel(vpii& v) {
	sort(v.begin(), v.end());
	std::vector<int> v_second;
	for(int i = 0; i < (int)v.size(); ++i)
		v_second.push_back( v[i].second );
	rmq = RMQ<int>(v_second);

	ll minL = 0;
	ll maxL = 2*1000*1000*1000+9;
	ll L;

	while (minL < maxL) {
    	L = (minL + maxL) / 2;

      	if (isAbleToReachLevel(v, (int)L))
        	minL = L + 1;
      	else
        	maxL = L;
    }
	return minL-1;
}

int maxLevelN_2(vpii& v) {
	int result = 0;
	for (int i = 0; i < (int)v.size(); ++i)
		for (int j = 0; j < (int)v.size(); ++j) {
			int tmp = min(v[i].first + v[j].first, v[i].second + v[j].second);
			result = max(result, tmp);
		}
	return result;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	//cin.sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x, &y);
	for (int i = 0; i < n; ++i) {
		int ai, bi;
		scanf("%d%d", &ai, &bi);
		a.push_back( make_pair(ai,bi) );
	}
	b = a;

	for (int j = 0; j < m; ++j) {
		int ci, di;
		scanf("%d%d", &ci, &di);
		c.push_back( make_pair(ci, di) );
	}

	int levelMax = maxLevel(a);
	int levelMin = maxLevel(c);

	if (levelMax >= levelMin) {
		printf("Max\n");
	} else {
		printf("Min\n");
	}

	return 0;
}
