#include<bits/stdc++.h>
using namespace std;

vector<int> findPrimes(int n){
    vector<int> primes(n + 1,  1), ans;
    for(int i=2;i<=n;i++){
        if(primes[i] == 1){
            for(int j=2*i;j<=n;j+=i){
                primes[j] = 0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(primes[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = findPrimes(n);
    cout<<" The primes upto n are : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N) + O(N log (log N))
// SC---> O(N)