#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    // Base Case
    if(i > n) return;
    cout<<" Ravi "<<endl;
    // function calls
    print(i+1, n);
}

int main(){
    int n;
    cin >> n;
    print(1, n);
    return 0;
}

// TC---> O(N)
// SC---> O(N) --> Stack Space