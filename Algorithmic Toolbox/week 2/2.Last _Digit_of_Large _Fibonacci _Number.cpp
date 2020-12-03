#include <iostream>
using namespace std;

/*int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
} */

int fibonacci_fast(int n) {
    // write your code here
   int fib[n];
   fib[0]=0;
   fib[1]=1;
   int i ;
   for(i = 2 ; i <=  n ; i++){
	   fib[i] = (fib[i-1]+ fib[i-2])%10;
   }
   int num = fib[n];
   return num;
}


int main() {
    int n = 0;
    cin >> n;

   // cout << fibonacci_naive(n) << '\n';

    cout << fibonacci_fast(n) << '\n';
    return 0;
}




