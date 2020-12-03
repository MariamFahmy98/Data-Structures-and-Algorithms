//example 1
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
vector < pair<int, int> > graph[10002];
void shortestPath(int source, vector <int>& distance) {
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push(make_pair(0, source));
	distance[source] = 0;
	while (!pq.empty()) {
		int vertix = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[vertix].size(); i++) {
			int v = graph[vertix][i].first;
			int w = graph[vertix][i].second;
			if (distance[v] > w + distance[vertix]) {
				distance[v] = w + distance[vertix];
				pq.push(make_pair(distance[v], v));
			}
		}
	}
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	int source, destination;
	cin >> source >> destination;
	vector <int> distance(verticesNum + 1, INF);
	shortestPath(source, distance);
	if (distance[destination] == INF) cout << "-1" << endl;
	else cout << distance[destination] << endl;
	return 0;
}