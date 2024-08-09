#include<bits/stdc++.h>
using namespace std;

void print(int i, int n, int sum){
    if(i > n ){
        cout<< sum <<endl;
        return;
    }
    sum += i;
    print(i + 1, n, sum);
}

int main(){
    int n;
    cin >> n;
    print(1, n, 0);
    return 0;
}

// TC---> O(N)
// SC---> O(N) --> Stack Space