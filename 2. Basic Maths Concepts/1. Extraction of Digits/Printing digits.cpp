#include<bits/stdc++.h>
using namespace std;

void extractDigits(int n){
    while(n > 0){
        int digit = n % 10;
        cout<< digit <<endl;
        n = n / 10;
    }
}

int main(){
    int n;
    cin >> n;
    extractDigits(n);
    return 0;
}

// TC---> O(Number of digits)
// SC---> O(1)