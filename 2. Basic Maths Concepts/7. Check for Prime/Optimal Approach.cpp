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


int main(){
    int number;
    cin >> number;
    bool ans = checkPrime(number);
    if(ans){
        cout<<" The given number is prime number";
    }
    else{
        cout<<" The given number is not prime number";
    }
    return 0;
}


// TC---> O(Sqrt(N))
// SC---> O(1)