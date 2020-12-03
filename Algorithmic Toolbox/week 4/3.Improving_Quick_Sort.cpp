#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
pair<long long int , long long int> partition3 (vector<long long int> &vect,long long int low , long long int high){
	long long int pivot =  vect[low];
	long long int i = low;
	long long int j = high;
	long long int temp1,temp2;
	long long int count = 0;
	while(i<j){
	     while(vect[i]<=pivot){
	    	 i++;
	     }
		while(vect[j]>pivot){
			j--;
		}
		if(i<j){
			if(vect[j] == pivot) count++;
			temp1=vect[i];
			vect[i]=vect[j];
			vect[j]=temp1;
		}
	}
	temp2=vect[low];
	vect[low]=vect[j];
	vect[j]=temp2;
    if(count == 0){
    	return make_pair(j,j);
    }else{
    	return make_pair(j,count+j);
    }
}
void quickSort(vector<long long int> &vect , long long int low , long long int high){
	if(low>=high) return;
	pair<long long int,long long int> result = partition3(vect,low,high);
	quickSort(vect,low,(result.first)-1);
	quickSort(vect,(result.second)+1,high);

}

int main(void){
	long long int size ;
	cin >> size ;
	vector<long long int> vect(size);
	for(long long int i = 0 ; i<size ; i++){
		cin >> vect[i];
	}
	quickSort(vect,0,size-1);
	for(long long int j = 0 ; j<size ; j++){
		cout<<vect[j]<<" ";
	}
	return 0;
}
