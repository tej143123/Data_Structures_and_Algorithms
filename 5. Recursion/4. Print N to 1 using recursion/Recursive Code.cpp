#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    // Base Case
    if(i < 1) return;
    cout<< i <<endl;
    // Function Calls
    print(i - 1, n);
}

int main(){
    int n;
    cin >> n;
    print(n, n);
    return 0;
}

// TC---> O(N)
// SC---> O(N) --> Stack Space