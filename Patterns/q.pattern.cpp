#include<bits/stdc++.h>
using namespace std;

void pattern17(int n){
    for(int i=0;i<n;i++){
        
        //spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" "; 
        }

        //alphabets
        char ch='A';
        int breakPoint=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){
            cout<<ch;
            if(j<=breakPoint) ch++;
            else ch--;
        }

        //spaces
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern17(n);
    return 0;
}

/*
    A    
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/