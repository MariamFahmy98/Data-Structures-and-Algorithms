
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

double maxValueOfItems (long long int totalWeight , vector<long long int> values , vector<long long int> weights){
         vector<double>ratio;
         double result = 0.0 ;
         long long int valueWeight = 0;
         long long int size = values.size();
         for(long long int i = 0 ; i< size ; i++){
        	 ratio.push_back((double)((double)values[i]/(double)weights[i]));
         }
         for(long long int i = 0 ; i< size ; i++){
        	 long long int index = max_element(ratio.begin(),ratio.end())-ratio.begin();
        	 if(totalWeight == 0)  break;
        	 if(weights[index] < totalWeight){
        		// result= (double)result + (double)(values[index]);
        		 valueWeight = weights[index];
        		// totalWeight-=weights[index];
        	 }else {
        		// result=(double) result + ((double)((double)ratio[index]*(double)valueWeight));
        		 valueWeight = totalWeight ;
        		 //totalWeight = 0;
        	 }
        	 result=(double) result + ((double)((double)ratio[index]*(double)valueWeight));
        	 totalWeight-=valueWeight;
        	 ratio[index]=0.0;
         }
         return result;
}

int main(void){
	long long int itemsNum , totalWeight;
	cin >> itemsNum >> totalWeight;
	vector<long long int> values ;
	vector<long long int> weights;
	//vector<double> ratio;
    long long int count = 1 ;
    while(count <= itemsNum){
    	long long int item , weight;
    	cin >> item >> weight;
    	values.push_back(item);
    	weights.push_back(weight);
    	//ratio.push_back(item/weight);
    	count++;
    }
    double result = maxValueOfItems(totalWeight ,  values , weights);
    cout.precision(10);
    cout << result;
	return 0;
}