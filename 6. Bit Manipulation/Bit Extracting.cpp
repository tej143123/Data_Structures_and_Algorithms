#include<bits/stdc++.h>
using namespace std;

int extractBit(int n, int i){
    int mask = (1 << i);
    if((mask & n) != 0 )
    return 1;
    return 0;
}

int main(){
    int n = 13, i = 1;
    cout<<" The ith bit is : "<<extractBit(n, i)<<endl;
    return 0;
}

// TC---> O(1)
// SC---> O(1)