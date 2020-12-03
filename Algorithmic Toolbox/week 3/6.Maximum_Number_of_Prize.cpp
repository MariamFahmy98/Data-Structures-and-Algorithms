#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	long long int number ;
	cin >> number ;
    vector<long long int> vect ;
    long long int j = number;
    long long int i = 1;
    while(true){
    	if(j <= 2*i){
    		vect.push_back(j);
    		break;
    	}
    	else{
    		vect.push_back(i);
    		j-=i;
    		i++;
    	}
    }
   cout <<vect.size()<<endl;
   long long int y = vect.size();
   for(long long int k = 0 ; k < y ; k++){
       cout<<vect[k]<<" ";
   }
	return 0 ;
}

