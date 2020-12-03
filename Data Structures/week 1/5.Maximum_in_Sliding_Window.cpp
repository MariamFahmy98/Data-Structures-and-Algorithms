#include<iostream>
#include<stack>
#include<vector>
#include <deque>
using namespace std;

vector<long long int> maxSlide (vector <long long int> const & vect , long long int m ){
   deque <long long int> dIndex;
   vector <long long int> result;
   long long int size = vect.size();
   if(size == 1){
	   result.push_back(vect[0]);
	   return result;
   }
   if( m == 1){
	   result = vect;
	   return result;
   }
   long long int i ;
   for( i = 0 ; i < m ; i++){
	   while( ! dIndex.empty() && vect[i] >= vect[dIndex.back()]){
		   dIndex.pop_back();
	   }
	   dIndex.push_back(i);
   }
   for( ; i < size ; i++){
	   result.push_back(vect[dIndex.front()]);
	   while( ! dIndex.empty() && dIndex.front() <= i-m){
		   dIndex.pop_front();
	   }
	   while( ! dIndex.empty() && vect[i] >= vect[dIndex.back()]){
		   dIndex.pop_back();
	   }
	   dIndex.push_back(i);
   }
   result.push_back(vect[dIndex.front()]);
   return result;
}
int main(){
	long long int n , m;
	cin >> n;
	vector <long long int> vect(n);
	for(long long int i = 0 ; i < n ; i++){
		cin >> vect[i];
	}
	cin >> m;
	vector<long long int> res;
	res = maxSlide (vect , m);
	for(long long int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
