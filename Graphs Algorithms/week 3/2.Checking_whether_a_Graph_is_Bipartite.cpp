//example 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> graph[100002];
int verticesNum, edgesNum;
bool bipartiteGraph(int vertix, vector <int>& color) {
	queue <int> qu;
	qu.push(vertix);
	color[vertix] = 0;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			if (color[graph[v][i]] == -1) {
				qu.push(graph[v][i]);
				color[graph[v][i]] = !(color[v]);
			}
			else {
				if (color[graph[v][i]] == color[v]) return false;
			}
		}
	}
	return true;
}
bool check(vector <int> &color) {
	for (int i = 1; i <= verticesNum; i++) {
		if (color[i] == -1) {
			if (!bipartiteGraph(i, color)) return false;
		}
	}
	return true;
}
int main(void) {
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector <int> color(verticesNum + 1, -1);
	cout << check ( color ) << endl;
	return 0;
}