#include<iostream>
#include <vector>
using namespace std;
int main(){
	long long int knapsackCapacity, totalGoldAmount;
	cin >> knapsackCapacity;
	cin >> totalGoldAmount;
    vector <long long int> goldWeights;
    goldWeights.push_back(0);
    vector < vector <long long int > > table(totalGoldAmount+1, vector<long long int>(knapsackCapacity+1,0));
    int count= 1;
    while(count <= totalGoldAmount){
    	long long int weight;
    	cin >> weight;
    	goldWeights.push_back(weight);
    	count++;
    }
    long long int i , j ;
    for(i = 0 ; i <= totalGoldAmount ; i++){
    	for(j = 0 ; j <= knapsackCapacity ; j++){
    		if( i == 0 || j == 0 ){
    			table[i][j] = 0;
    		}
    		else if ( j < goldWeights[i]){
    			table[i][j] = table[i-1][j];
    		}
    		else{
    			table[i][j] = max( table[i-1][j] , table[i-1][j-goldWeights[i]] + goldWeights[i]);
    		}
    	}
    }

    cout << table[i-1][j-1];
    		return 0;
}

