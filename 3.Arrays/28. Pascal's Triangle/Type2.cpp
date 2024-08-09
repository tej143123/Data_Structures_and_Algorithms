/* Given the row number n. Print the n-th row of Pascal’s triangle. */

#include<bits/stdc++.h>
using namespace std;

void pascalTriangle(int n){
    long long ans=1;
    // Printing first element
    cout<<ans<<" ";

    // Printing the rest of the part, i--->col
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/(i);
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    pascalTriangle(n);
    return 0;
}

// TC---> O(N)
// SC---> O(1)