//example 3
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
stack <int> st;
vector <int> originalG[10002];
vector <int> reverseG[10002];
void DFS(int vertix, vector<int>graph[], vector <bool>& visited) {
	visited[vertix] = true;
	for (int i = 0; i < graph[vertix].size(); i++) {
		if (!visited[graph[vertix][i]]) DFS(graph[vertix][i], graph, visited);
	}
	if (graph == originalG) st.push(vertix);
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		originalG[edge1].push_back(edge2);
		reverseG[edge2].push_back(edge1);
	}
	vector <bool> visitedOriginal(verticesNum + 1, false);
	vector <bool> visitedReversed(verticesNum + 1, false);
	for (int i = 1; i <= verticesNum; i++) {
		if (!visitedOriginal[i]) DFS(i, originalG, visitedOriginal);
	}
	int count = 0;
	while (!st.empty()) {
		if (!visitedReversed[st.top()]) {
			DFS(st.top(), reverseG, visitedReversed);
			count++;
		}
		st.pop();
	}
	cout << count << endl;
	return 0;
}