// first exercise
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
	int first, last;
	cin >> first >> last;
	vector <bool> visited(verticesNum + 1, false);
	DFS(first, visited);
	if (visited[first] && visited[last]) cout << "1" << endl;
	else cout << "0" << endl;
	return 0;


}