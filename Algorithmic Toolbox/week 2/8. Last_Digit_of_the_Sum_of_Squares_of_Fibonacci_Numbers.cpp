#include<iostream>
#include<vector>
using namespace std;
int fib_power(unsigned long long int number){
	vector <int> vect;
	vect.push_back(0);
	vect.push_back(1);
	unsigned long long int i ;
    for( i = 2 ; i<= number%60; i++){
    	vect.push_back((vect[i-1]+vect[i-2])%10);
    }
    int result = (vect[number%60]*(vect[number%60]+vect[(number%60)-1]))%10;
    return result ;
}
int main(void){
	unsigned long long int number;
	cin>>number;
	cout<<fib_power(number);
	return 0;
}
