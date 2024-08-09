#include<bits/stdc++.h>
using namespace std;

int findSqrt(int n){
    int ans = 1;
    int low = 1, high = n;
    while(low <= high){
        long long mid =(low + high)/2;
        long long val = (mid * mid);
        if(val <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    int n = 28;
    cout<<"The square root of a number is : "<<findSqrt(n)<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)