#include<bits/stdc++.h>
using namespace std;

int findPower(int x, int n){
    int ans = 1;
    while( n > 0){
        if(n % 2 == 1){
            ans *= x;
            n = n - 1;
        }
        else{
            x = x * x;
            n = n / 2;
        }
    }

    return ans;
}

int main(){
    int x, n;
    cin>>x>>n;
    int ans = findPower(x, n);
    cout<<" The power(x, n) is : "<<ans;
    return 0;
}

// TC---> O(log2 (N))
// SC----> O(1)