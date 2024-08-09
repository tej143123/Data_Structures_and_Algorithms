#include<bits/stdc++.h>
using namespace std;

int findSqrt(int n){
    int ans = sqrt(n);
    return ans;
}


int main(){
    int n = 28;
    cout<<"The square root of a number is : "<<findSqrt(n)<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)