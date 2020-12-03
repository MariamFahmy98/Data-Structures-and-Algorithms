#include <iostream>
#include <cmath>
#include<sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
long long int minAndmax (long long int op1 , long long int op2 , char op){
	long long int result;
	if(op == '*' ){
		result = op1 * op2;
	}
	else if( op == '+'){
		result = op1 + op2;
	}
	else if (op == '-') {
		result = op1 - op2;
	}
	return result;
}
long long int parentheses (vector <long long int> digit , vector <char> operations){
	  long long int size = digit.size();   //n=size
      vector < vector<long long int > > minTable (size+1,vector<long long int>(size+1,0));
      vector < vector<long long int > > maxTable (size+1,vector<long long int>(size+1,0));
      long long int diagonalNum , rowNum , columnNum;
      for( rowNum = 1 ; rowNum <= size ; rowNum++){
    	  minTable[rowNum][rowNum] = digit[rowNum-1];
    	  maxTable[rowNum][rowNum] = digit[rowNum-1];
      }
      for(diagonalNum = 1 ; diagonalNum <= size-1 ; diagonalNum++){
    	  for(rowNum = 1 ; rowNum <= size-diagonalNum ; rowNum++){
    		  columnNum = rowNum + diagonalNum ;
    		  long long int minValue = 10000000000000000;
    		  long long int maxValue = -10000000000000000;
    		  for(long long int k = rowNum ; k < columnNum ; k++){
    			  long long int a , b , c , d ;
                  a = minAndmax(maxTable[rowNum][k],maxTable[k+1][columnNum],operations[k-1]);
                  b = minAndmax(maxTable[rowNum][k],minTable[k+1][columnNum],operations[k-1]);
                  c = minAndmax(minTable[rowNum][k],minTable[k+1][columnNum],operations[k-1]);
                  d = minAndmax(minTable[rowNum][k],maxTable[k+1][columnNum],operations[k-1]);
                  minValue = min(minValue,min(a,min(b,min(c,d))));
                  maxValue = max(maxValue,max(a,max(b,max(c,d))));
    		  }
    		  minTable[rowNum][columnNum] = minValue;
    		  maxTable[rowNum][columnNum] = maxValue;
    	  }
      }

      return maxTable[1][size];

}
int main(){
	string expression;
	cin >> expression;
	vector <long long int> digits;
	vector <char> operations;
	int length = expression.length();
	for( int i = 0 ; i < length ; i++){
		if( i%2 == 0){
			  long long int digit =  stoll ( expression.substr(i,1) ) ;
    		  digits.push_back(digit);
    	  }
    	  else{
    		  operations.push_back(expression[i]);
    	  }
      }
	long long int result = parentheses(digits,operations);

	cout << result;
return 0;
}



