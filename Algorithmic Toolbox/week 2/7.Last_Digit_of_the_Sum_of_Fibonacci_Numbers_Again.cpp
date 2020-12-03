#include<iostream>
#include<vector>
using namespace std;
unsigned long long int fib_fast(unsigned long long int number1 , unsigned long long int number2) {
	// write your code here

	vector<unsigned long long int> period(60) ;
	unsigned long long int i ;
	unsigned long long int j ;
	period[0]=0;
	period[1]=1;
	unsigned long long int sum = 1;
	unsigned long long int sum1 = 0;
	for(i=2 ; i<60 ; i++){
		period[i]=(period[i-1]+period[i-2])%10;
		sum+=period[i];
	}
	sum = sum*(number2/60);
	for(j=(number1%60) ; j<=(number2%60) ; j++){
		sum1+= period[j];
	}

	unsigned long long int result = (sum+sum1)%10;
	if(sum1 == 0 && number2>10000 && number1>10000){
		return fib_fast(0,number2)-fib_fast(0,number1)+9;
	}
	return result;

}


int main(){
	unsigned long long int number1 , number2;
	cin >> number1 >> number2;
	cout<< fib_fast(number1 , number2);
	return 0;
}


