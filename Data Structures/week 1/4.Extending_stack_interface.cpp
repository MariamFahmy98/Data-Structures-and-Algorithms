#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<string>
using namespace std;
class stackMax {
	stack <long long int> st;
public:
	void push(long long int value){
		if(st.empty()) st.push(value);
		else{
			if(value > st.top())
				st.push(value);
			else
				st.push(st.top());
		}
	}
	void pop(){
		st.pop();
	}
	long long int max(){
		return st.top();
	}
};
int main(void){
	long long int queries;
	cin >> queries;
    long long int count = 1;
    vector <long long int> results;
    stackMax st;
    while(count <= queries){
    	string str;
    	cin >> str;
    	if(str == "push"){
    		long long int value;
    		cin >> value;
    		st.push(value);
    	}
    	else if(str == "pop"){
    		st.pop();
    	}
    	else{
        results.push_back( st.max() );
    	}
    	count++;
    }
    if(results.size() == 0){
    	cout<<" "<<endl;
    }
    else{
    	for(long long int i = 0 ; i < results.size() ; i++){
    		cout<<results[i]<<endl;
    	}
    }
	return 0;
}

