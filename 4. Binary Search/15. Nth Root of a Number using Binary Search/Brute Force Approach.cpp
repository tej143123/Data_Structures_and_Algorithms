#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    double ans = 1.0;
    for(int i=1;i<=n;i++){
        ans = ans * x;
    }
    return ans;
}

int findNthRoot(int n, int m){
    for(int i=1;i<=m;i++){
        if(myPow(i, n) == m){
            return i;
        }
        else if(myPow(i, n) > m){
            break;
        }
    }
    return -1;
}


int main(){
    int n = 3, m = 27;
    cout<<" The nth of m is : "<<findNthRoot(n, m)<<endl;
    return 0;
}

// TC---> O(M * N)
// SC---> O(1)