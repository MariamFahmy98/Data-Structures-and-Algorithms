#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long minNumOfStations ( vector <long long > fuelStations , long long maxDistanceCovered){
	long long minNum = 0;
	long long index = 0;
	long long size = fuelStations.size();
	while(index <= size-2){
		long long filledFuel = index ;
		while(index <= size-2 && (fuelStations[index+1] - fuelStations[filledFuel])<= maxDistanceCovered){
			index++;
		}

		if(index == filledFuel){
			return -1;
		}
		if(index <= size-2) {
			minNum++;
		}
	}
   return minNum;
}
int main(void){
	long long distance ;
	long long maxDistCovered ;
	long long count ;
	long long count1 = 1;
	vector<long long> fuelStations ;
	cin >> distance ;
	cin >> maxDistCovered ;
	cin >> count ;
	fuelStations.push_back(0);
	while(count1 <= count){
		long long var ;
		cin >> var ;
		fuelStations.push_back(var);
		count1++;
	}
	fuelStations.push_back(distance);
	long long result = minNumOfStations(fuelStations , maxDistCovered);
    cout << result;
	return 0;
}






