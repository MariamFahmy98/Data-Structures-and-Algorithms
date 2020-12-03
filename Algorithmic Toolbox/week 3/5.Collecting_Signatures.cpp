#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
long long int counter = 0;
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second < b.second);
}
vector<long long int > buildingSignatures (vector<pair<long long int , long long int>> segments , long long int number){
	vector<long long int> points;
	long long int i = 0;
	long long int j = 1;
	while(i< number){
		long long step = i ;
		while(i < number && segments[step].second >= segments[j].first && segments[step].second <= segments[j].second){
             i++;
             j++;
		}
		i++;
		j++;
		points.push_back(segments[step].second);
		counter++;
	}
	return points;
}
int main(void){
	long long int number ;
	cin >> number;
	vector<long long int> vect1 ;
	vector<long long int> vect2;
	vector<pair<long long int , long long int>> vect ;
	long long int count = 1 ;
	while(count <= number){
		long long int value1 , value2 ;
		cin >> value1 >> value2 ;
		vect1.push_back(value1);
		vect2.push_back(value2);
		count++;
	}
	for(long long int i = 0 ; i<number ; i++){
		vect.push_back(make_pair(vect1[i],vect2[i]));
	}
	sort(vect.begin(),vect.end(),sortinrev);
    vector<long long int> result ;
    result = buildingSignatures(vect , number);
    cout << counter <<endl;
    for(long long int i = 0 ; i< counter ; i++){
    	cout << result[i] <<" ";
    }
	return 0;
}
