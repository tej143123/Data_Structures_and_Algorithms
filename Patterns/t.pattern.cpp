#include<bits/stdc++.h>
using namespace std;

void pattern20(int n){
    int spaces=2*n-2;
    for(int i=1;i<=2*n-1;i++){
        //stars
        int stars=i;
        if(i>n) stars=2*n-i;
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }

        //spaces
        for(int j=0;j<spaces;j++){
            cout<<" ";
        }

        //stars
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        if(i<n) spaces-=2;
        else spaces+=2;
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern20(n);
    return 0;
}

/*
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/