
#include<iostream>
using namespace std;
long long commonDivider(long long num1 , long long num2){
   if(num2==0)
	   return num1;
   long long remainder;
   remainder = (num1%num2);
   return commonDivider(num2,remainder);
}

long long commonMultiplier(long long num1 , long long num2){
	long long gcd = commonDivider(num1,num2);
	long long result = num1/gcd;
	long long product = result*num2;
	return product;
}
int main(){
	long long num1 , num2 ;
	cin>>num1 >>num2;
	cout<< commonMultiplier(num1, num2)<<endl;
	return 0;
}
