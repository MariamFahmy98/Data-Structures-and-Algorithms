#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	long long number;
	cin >> number;
	int m10 = 0 , m5 = 0 , m1 = 0;
	m10 = number/10;
	number = number%10;
	m5 = number/5 ;
	number = number%5;
	m1 = number;
	long long count = m10+m5+m1;
	cout<<count;
	return 0 ;
}



