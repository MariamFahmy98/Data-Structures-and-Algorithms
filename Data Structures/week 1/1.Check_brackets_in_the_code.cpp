#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool Isclosing(char c){
	if(c == ')' || c == '}' || c ==']') return true;
	else return false;
}
bool IsOpening(char c){
	if(c == '(' || c == '{' || c =='[') return true;
		else return false;
}
bool pairing (char c1 , char c2){
	if(c1 == '[' && c2 == ']') return true;
	else if (c1 == '(' && c2 ==')') return true;
	else if (c1 == '{' && c2 =='}') return true;
	else return false;
}
void checkingParentheses(string phrase){
	stack <char> s;
	stack <long> positions;
	long length = phrase.length();
	long i;
    for(i = 0 ; i<length ; i++){
    	if(IsOpening(phrase[i])){
    		s.push(phrase[i]);
    		positions.push(i+1);
    	}
    	else if(Isclosing(phrase[i])){
    		if(s.empty()) {
    			cout << i+1 <<endl;
    			return;
    		}
    		if( pairing(s.top(),phrase[i])){
    			s.pop();
    			positions.pop();
    		}
    		else{
    			cout<< i+1 <<endl;
    			return;
    		}
    	}
    }
    if( s.empty()) cout<<"Success"<<endl;
    else cout<<positions.top() <<endl;
}
int main(void){
	string phrase;
	cin >> phrase;
	checkingParentheses(phrase);
	return 0;
}



