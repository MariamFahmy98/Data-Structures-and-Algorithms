#include<iostream>
using namespace std;
long long commonDivider(long long , long long);
int main(){
	int num1 , num2;
	cin>>num1 >> num2;
   cout<< commonDivider(num1 , num2) <<endl;
	return 0 ;
}

long long commonDivider(long long num1 , long long num2){
   if(num2==0)
	   return num1;
   long long remainder;
   remainder = (num1%num2);
   return commonDivider(num2,remainder);
}

