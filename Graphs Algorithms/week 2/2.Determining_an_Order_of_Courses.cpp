// example 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
vector <int> table[100002];
stack <int> st;
void DFS(int vertix, vector <bool>& visited) {
	visited[vertix] = true;
	for (int i = 0; i < table[vertix].size(); i++) {
		if (!visited[table[vertix][i]]) DFS(table[vertix][i], visited);
	}
	st.push(vertix);
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		table[edge1].push_back(edge2);
	}
	vector <bool> visited(verticesNum + 1, false);
	for (int i = 1; i <= verticesNum; i++) {
		if (!visited[i]) DFS(i, visited);
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}