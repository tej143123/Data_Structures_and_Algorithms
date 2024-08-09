#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0;i<2*n;i++){
        int stars=i;
        if(i>n) stars=2*n-i;
        for(int j=0;j<stars;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern1(n);
    return 0;
}

/*

*
**
***
****
*****
****
***
**
*

*/