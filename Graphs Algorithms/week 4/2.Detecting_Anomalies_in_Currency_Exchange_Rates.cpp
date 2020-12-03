//example 2
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
vector < pair<int,int> > graph[1002];
int main() {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	vector <int> minDst(verticesNum + 1, INF);
	// assume source vertix is 1
	int source = 1;
	minDst[source] = 0;
	for (int i = 1; i <= verticesNum - 1; i++) {
		for (int j = 1; j <= verticesNum; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int vertix = graph[j][k].first;
				int weight = graph[j][k].second;
				if (minDst[vertix] > weight + minDst[j]) {
					minDst[vertix] = weight + minDst[j];
				}
			}
		}
	}
	for (int j = 1; j <= verticesNum; j++) {
		for (int k = 0; k < graph[j].size(); k++) {
			int vertix = graph[j][k].first;
			int weight = graph[j][k].second;
			if (minDst[vertix] > weight + minDst[j]) {
				cout << "1" << endl;
				return 0;
			}
		}
	}
	cout << "0" << endl;
	return 0;
}