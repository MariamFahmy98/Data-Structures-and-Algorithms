#include <iostream>
#include <cmath>
#include<sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include<numeric>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int subsets (vector<int> values){
	int totalSum = accumulate(values.begin() , values.end() , 0);
	if(totalSum % 3 != 0 || values.size()<3) return 0;
		vector< vector<int> >table((totalSum / 3) + 1 , vector<int> (values.size()+1,0));
		int row,column;
			for( row = 1 ; row <= totalSum/3 ; row++){
				for( column= 1 ; column <= values.size() ; column++){
					int k = row-values[column-1];
					if( row == values[column-1] || (k>0 && table[k][column-1] > 0)){
						table[row][column] = table[row][column-1] + 1;
						if(table[row][column] == 3){
							table[row][column]--;
						}
					}
					else if(row == (values[column-1] + values[column-2]) && row != values[column-1]){
						table[row][column] = table[row][column-1] + 1;
						if(table[row][column] == 3){
							table[row][column]--;
						}
					}
					else{
						table[row][column] = table[row][column-1];
					}
				}
			}
			if(table[row-1][column-1] == 2) return 1;
			else return 0;
}
int main(){
	int number;
	vector <int> values;
	cin >> number;
	int count = 1;
	while(count <= number){
		int val;
		cin >> val;
		values.push_back(val);
		count++;
	}

    int result = subsets(values);
    cout<<result;
	return 0;
}

