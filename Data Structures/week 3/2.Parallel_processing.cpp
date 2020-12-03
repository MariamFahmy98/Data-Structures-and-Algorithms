#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

class jobQueue{
private:
	long long int threadsNum;
	vector<long long int> jobOrder;
	vector<long long int> threadsOrder;
	vector<long long int> startingTime;
	void dataInput();
	void dataOutput();
	void sequence();
public:
	void solve();
};
void jobQueue::dataInput(){
	long long int m;
	cin >> threadsNum >> m;
	long long int count=1;
	while(count <= m){
		long long int value;
		cin >> value;
		jobOrder.push_back(value);
		count++;
	}
}
void jobQueue::dataOutput(){
	for(long long int i = 0 ; i < jobOrder.size() ; i++)
		cout<< threadsOrder[i] <<" "<<startingTime[i]<<endl;
}
void jobQueue::sequence(){
	priority_queue< pair<long long int, long long int> , vector<pair<long long int, long long int> > , greater<pair<long long int,long long int>> > nextFree;
	for(long long int i = 0 ; i < threadsNum ; i++){
		nextFree.push(make_pair(0,i));
	}
	for(long long int i = 0 ; i < jobOrder.size() ; i++){
		threadsOrder.push_back(nextFree.top().second);
		startingTime.push_back(nextFree.top().first);
		nextFree.pop();
		nextFree.push(make_pair(startingTime[i]+jobOrder[i] , threadsOrder[i]));
	}


}
void jobQueue::solve(){
	dataInput();
	sequence();
	dataOutput();
}
int main(void){
	jobQueue job;
	job.solve();
	return 0;
}

