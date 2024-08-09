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
int countPrimes(int n1, int n2){
    int cnt = 0;
    for(int i=n1;i<=n2;i++){
        if(checkPrime(i)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n1, n2;
    cin>>n1>>n2;
    int ans = countPrimes(n1, n2);
    cout<<" The number of prime numbers between " <<n1<<" and " <<n2<<" are : "<<ans<<endl;
    return 0;
}

// TC---> O(N2 - N1) * O(sqrt(N))
// SC---> O(1)