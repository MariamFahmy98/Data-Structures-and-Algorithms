//example 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> table[10002];
void DFS(int vertix, vector <bool>& visited) {
	visited[vertix] = true;
	for (int i = 0; i < table[vertix].size(); i++) {
		if (!visited[table[vertix][i]]) DFS(table[vertix][i], visited);
	}
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		table[edge1].push_back(edge2);
		table[edge2].push_back(edge1);
	}
	vector <bool> visited(verticesNum + 1, false);
	int count = 0;
	for (int i = 1; i <= verticesNum; i++) {
		if (!visited[i]) {
			DFS(i, visited);
			count++;
		}
	}
	cout << count << endl;
	return 0;
}