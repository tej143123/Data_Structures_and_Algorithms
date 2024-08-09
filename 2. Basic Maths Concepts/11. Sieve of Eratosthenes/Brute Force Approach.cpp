#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int number){
    int cnt = 0;
    for(int i=1;i*i<=number;i++){
        if((number % i) == 0){
            cnt++;
            if((number / i) != i){
                cnt++;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

vector<int> findPrimes(int n){
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(checkPrime(i)){
            primes.push_back(i);
        }
    }

    return primes;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = findPrimes(n);
    cout<<" The Primes upto n are: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N * sqrt(N))
// SC---> O(N)