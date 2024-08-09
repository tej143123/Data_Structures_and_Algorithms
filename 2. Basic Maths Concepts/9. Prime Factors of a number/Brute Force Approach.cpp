#include<bits/stdc++.h>
using namespace std;

bool checkForPrime(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n % i == 0){
            cnt++;
            if((n / i) != i){
                cnt++;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

vector<int> findPrimeFactors(int n){
    vector<int>ans;
    for(int i=2;i<=n;i++){
        if(n % i == 0){
            if(checkForPrime(i)){
                ans.push_back(i);
            }
        }
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = findPrimeFactors(n);
    cout<<" The Prime Factors are : ";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N * sqrt(N))
// SC---> O(Number of prime factors)