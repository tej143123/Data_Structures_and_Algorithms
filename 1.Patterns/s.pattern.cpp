#include<bits/stdc++.h>
using namespace std;

void pattern19(int n){
    int spaces=0;
 for(int i=0;i<n;i++){
    //stars
    for(int j=1;j<=n-i;j++){
        cout<<"*";
    }

    //spaces
    for(int j=0;j<spaces;j++){
        cout<<" ";
    }

    //stars
    for(int j=1;j<=n-i;j++){
        cout<<"*";
    }
    spaces+=2;
    cout<<endl;
 }
    int iniSpaces=2*n-2;
    for(int i=1;i<=n;i++){
        //stars

        for(int j=1;j<=i;j++){
        cout<<"*";
       }

        //spaces
        for(int j=0;j<iniSpaces;j++){
            cout<<" ";
        }

    //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        iniSpaces-=2;
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern19(n);
    return 0;
}

/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/