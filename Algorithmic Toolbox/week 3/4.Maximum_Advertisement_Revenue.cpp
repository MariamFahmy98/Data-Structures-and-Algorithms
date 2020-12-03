#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	long long num ;
	cin >> num ;
	vector < long long > vect1 ;
	vector < long long > vect2 ;
	long long count1 = 1 ;
	long long count2 = 1;
	long long result  = 0 ;
	while(count1 <= num){
		long long var ;
		cin >> var ;
		vect1.push_back(var);
		count1++;
	}
	while(count2 <= num){
		long long var ;
		cin >> var ;
		vect2.push_back(var);
		count2++;
	}
    sort(vect1.begin(),vect1.end());
    sort(vect2.begin(),vect2.end());
    for(long long i = 0 ; i<num ; i++){
    	result += vect1[i]*vect2[i];
    }
    cout <<result;
	return 0 ;
}


