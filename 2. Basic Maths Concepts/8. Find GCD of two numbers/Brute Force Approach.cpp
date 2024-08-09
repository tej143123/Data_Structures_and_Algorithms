#include<bits/stdc++.h>
using namespace std;

int findGCD(int n1, int n2){
    int gcd = 1;
    for(int i=1;i<=min(n1, n2);i++){
        if((n1 % i) == 0 && (n2 % i) == 0){
            gcd = i;
        }
    }
    return gcd;
}

int main(){
    int n1 , n2;
    cin >> n1;
    cin >> n2;
    cout<<findGCD(n1, n2)<<endl;
    return 0;
}

// TC---> O(min(n1, n2))
// SC---> O(1)