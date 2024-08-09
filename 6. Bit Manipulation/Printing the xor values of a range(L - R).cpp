#include<bits/stdc++.h>
using namespace std;

int findXORR(int x){
    if(x % 2 == 0) return x;
    else if(x % 2 == 1) return 1;
    else if(x % 2 == 2) return x + 1;
    // if(n % 2 == 3)
    return 0;
}

int findXOR(int l, int r){
    int R = findXORR(r);
    int L = findXORR(l-1);
    return R ^ L;
}

int main(){
    int l = 2, r = 4;
    cout<<findXOR(l, r)<<endl;
    return 0;
}


// TC---> O(1)
// SC---> O(1)