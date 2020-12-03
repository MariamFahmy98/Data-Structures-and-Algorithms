#include<iostream>
#include<vector>
using namespace std;


unsigned long long int fib_fast(unsigned long long int number,unsigned long long int mod) {
	// write your code here
	vector<unsigned long long int> period ;
	unsigned long long int i = 2 ;
	period.push_back(0);
	period.push_back(1);
	//unsigned long long int limit = 2;
	while(1){
		period.push_back((period[i-1]+period[i-2])%mod);
		if(period[i] == 1 && period[i-1] == 0 ) {
			period.pop_back();
			period.pop_back();
			break;
		}
		i++;
	}
	unsigned long long int length = i-1;
	unsigned long long int var = number%length;
	unsigned long long int  result = period[var];
	return result;
	//fib.clear();
	//period.clear();
}

