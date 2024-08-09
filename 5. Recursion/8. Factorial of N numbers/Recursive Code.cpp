#include<bits/stdc++.h>
using namespace std;

int findFactorial(int n){
    // Base Case
    if( n == 0){
        return 1;
    }
    // problem broken down into 2 parts and then combined
    return n * findFactorial(n - 1);
}

int main(){
    int n; 
    cin >> n;
    cout<<findFactorial(n)<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N) ---> Stack Space