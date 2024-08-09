#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){
    if(n % 2 == 0) return n;
    else if(n % 2 == 1) return 1;
    else if(n % 2 == 2) return n + 1;
    // if(n % 2 == 3)
    return 0;
}

int main(){
    int n = 5;
    cout<<findXOR(n)<<endl;
    return 0;
}
