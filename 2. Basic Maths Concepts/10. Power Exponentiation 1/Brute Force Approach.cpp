#include<bits/stdc++.h>
using namespace std;

int findPower(int x, int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans *= x;
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

// TC---> O(N)
// SC----> O(1)