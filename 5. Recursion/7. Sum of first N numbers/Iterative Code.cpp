#include<bits/stdc++.h>
using namespace std;

int findSum(int sum, int n){
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout<< findSum(0, n) <<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)