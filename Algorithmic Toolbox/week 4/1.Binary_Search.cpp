#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int binary_search(const vector<long long int> &vect, long long int key) {
  long long int low = 0, high = (long long int)vect.size();
  //write your code here
  long long int middle;
  	while(low <= high){
  		middle=(low+high)/2;
  		if(key<vect[middle]) high=middle-1;
  		else if(key>vect[middle]) low=middle+1;
  		else return middle;
  	}
  	return -1;
}

int main() {
  long long int n;
  std::cin >> n;
  vector<long long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long int m;
  std::cin >> m;
  vector<long long int> b(m);
  for (long long int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long long int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}


