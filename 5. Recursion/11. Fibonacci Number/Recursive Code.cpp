#include<bits/stdc++.h>
using namespace std;

int findFibonacci(int n){
    // Base Case
    if(n <= 1) return n;
    return findFibonacci(n - 1) + findFibonacci(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout<<findFibonacci(n)<<endl;
    return 0;
}

// TC---> O(2^N) ---> Worst Case
// SC---> O(N)