#include<bits/stdc++.h>
using namespace std;

int findGCD(int a, int b){
    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    return a;
}

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    cout<<findGCD(a, b);
    return 0;
}


// TC---> O(logɸ (min(a,b))), where ɸ is 1.61
// SC---> O(1)