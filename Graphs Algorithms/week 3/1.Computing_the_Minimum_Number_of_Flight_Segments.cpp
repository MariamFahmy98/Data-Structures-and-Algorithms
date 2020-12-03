//example1
#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f3f
using namespace std;
vector <int> graph[100002];

int shortestPath(int vertix, int lastV , vector <int> &dis) {
	dis[vertix] = 0;
	queue <int> qu;
	qu.push(vertix);
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		if (v == lastV) return dis[v];
		for (int i = 0; i < graph[v].size(); i++) {
			if (dis[graph[v][i]] == -1) {
				dis[graph[v][i]] = dis[v] + 1;
				qu.push(graph[v][i]);
			}
		}
	}
	return -1;
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int start, last;
	cin >> start >> last;
	vector <int> distance(verticesNum + 1, -1);
	cout << shortestPath(start, last, distance) << endl;
	
	return 0;
}