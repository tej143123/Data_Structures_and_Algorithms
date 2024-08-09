#include<bits/stdc++.h>
using namespace std;

int findFibonacci(int n){
    
    int last = 1; // (i - 1)th term
    int slast = 0; // (i - 2)th term
    int cur;
    for(int i=2;i<=n;i++){
        cur = last + slast;
        slast = last;
        last = cur;
    }
    return cur;
}

int main(){
    int n;
    cin >> n;
    cout<<findFibonacci(n)<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)