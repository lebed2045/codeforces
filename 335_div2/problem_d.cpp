#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

class Edge {
public:
	int w;
	bool isSpanningTree;
	int a, b;
	int i;
	Edge(int _w, bool _isSpanningTree, int _i) {
		w = _w;
		isSpanningTree = _isSpanningTree;
		i = _i;
	}
};

int n,m;
vector <Edge> e;
queue <pair<int,int>> avaliableEdges;


int main() {
	ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m;
	//scanf("%d%d",&n, &m);
	for (int i = 0; i < m; i++) {
		int ai, bi;
		cin >> ai >> bi;
		//scanf("%d%d", &ai, &bi);
		e.push_back( Edge(ai,bi == 1, i) );
	}
	sort(e.begin(), e.end(), 
		[](Edge &a, Edge &b) -> bool {
			return a.w < b.w || (a.w == b.w && a.isSpanningTree > b.isSpanningTree);
		});
	bool answerExists = true;
	int lastVertex = 1;
	for (auto &edge: e) {
		if (edge.isSpanningTree) {
			//join to componets
			edge.a = 1;
			edge.b = ++lastVertex;
			if (lastVertex > n) {
				answerExists = false;
				break;
			}
			for (int i = 2; i < lastVertex; i++) {
				if (avaliableEdges.size() > m) break;
				//add new avaliable edges
				avaliableEdges.emplace(i,lastVertex);
			}
		} else {
			//add to existing component
			if (avaliableEdges.empty()) {
				answerExists = false;
				break;
			}
			edge.a = avaliableEdges.front().first;
			edge.b = avaliableEdges.front().second;
			avaliableEdges.pop();
		}
	}

	if (answerExists) {
		sort(e.begin(), e.end(), 
			[](Edge& a, Edge& b) -> bool { 
				return a.i < b.i;
			});
		for (auto &edge: e) {
			//cout << edge.a << " " << edge.b << "\n";
			printf("%d %d\n", edge.a, edge.b);
		}
	} else {
		//cout << "-1" << endl;
		printf("-1\n");
	}
	return 0;
}