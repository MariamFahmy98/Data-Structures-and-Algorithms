#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (void){
	long long int numCoins = 3;
	long long int coins[3]={1,3,4};
	long long int money;
	cin >> money;
	long long int table [3][money+1];
	long long int i, j;
	long long int temp = 0;
    for(i = 0 ; i< numCoins ; i++){
    	for(j = 0 ; j < money+1 ; j++){
    		if(i == 0){
             table[i][j]= j;
             continue;
    		}
    		if(j >= coins[i] && i!=0){
    			temp = table[i][j-coins[i]]+1;
    			if(temp < table[i-1][j]){
    				table[i][j]=temp;
    			}
    			else{
    				table[i][j]=table[i-1][j];
    			}
    		}
    		else{
    			table[i][j] = table[i-1][j];
    		}

    	}
    }
    cout<< table[i-1][money];
    return 0;
}

