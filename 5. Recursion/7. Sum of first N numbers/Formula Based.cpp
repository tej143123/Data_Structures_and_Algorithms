#include<bits/stdc++.h>
using namespace std;

int findSum(int sum, int n){
    sum = (n * (n  + 1)) / 2;
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout<< findSum(0, n) <<endl;
    return 0;
}

// TC---> O(1)
// SC---> O(1)