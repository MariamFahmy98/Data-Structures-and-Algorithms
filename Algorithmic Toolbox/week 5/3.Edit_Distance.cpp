#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int main(){
	string str1, str2;
	cin >> str1 >> str2;
	int size1 = str1.length();
	int size2 = str2.length();
	int table[size2+1][size1+1];
	int i, j;
	for(i = -1 ; i< size2 ; i++){
		for(j = -1 ; j < size1 ;j++){
           if( i == -1 ){
        	   table[i+1][j+1] = j+1;
           }
           if( j == -1 ){
        	   table[i+1][j+1] = i+1;
           }
           if (i != -1 && j!= -1 && str2[i] == str1[j]){
        	   table[i+1][j+1] = table[i][j];
           }
           if(i != -1 && j!= -1 && str2[i] != str1[j]){
        	   table[i+1][j+1] = 1 + min ( min( table[i][j+1] , table[i][j]) , table[i+1][j]);
           }
		}
	}
	cout << table[i][j];


	return 0;
}

