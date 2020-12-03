// example 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
struct node {
	int rank;
	int parent;
};
map <int, node> mapping;

void makeSet(int data) {
	node newNode;
	newNode.rank = 0;
	newNode.parent = data;
	mapping[data] = newNode;
}

node findSet(int data) {
	if (mapping[data].parent == data) return mapping[data];
	return findSet(mapping[data].parent);
}

bool unionSet(int data1, int data2) {
	node newData1 = findSet(data1);
	node newData2 = findSet(data2);
	if (newData1.parent == newData2.parent) return false;

	if (newData1.rank >= newData2.rank) {
		newData1.rank == newData2.rank ? mapping[newData1.parent].rank++ : mapping[newData1.parent].rank;
		mapping[newData2.parent].parent = newData1.parent;
	}
	else mapping[newData1.parent].parent = newData2.parent;
	return true;
}
int main(void) {
	int vertices;
	cin >> vertices;
	vector < pair <int, int> > points(vertices);
	for (int i = 0; i < vertices; i++) cin >> points[i].first >> points[i].second;
	vector < pair <double, pair<int, int> > >edges;
	for (int i = 0; i < vertices - 1; i++) {
		for (int j = i + 1; j < vertices; j++) {
			double dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
			edges.push_back(make_pair(dist, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < vertices; i++) makeSet(i);
	double result = 0.0;
	for (int i = 0; i < edges.size(); i++) {
		if (unionSet(edges[i].second.first, edges[i].second.second)) result += edges[i].first;
	}
	cout << setprecision(10) << result << endl;
	return 0;
}