#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        
        //stars
        for(int j=0;j<i*2+1;j++){
            cout<<"*";
        }
        
        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
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
   ***
  *****
 ******* 
*********
*/