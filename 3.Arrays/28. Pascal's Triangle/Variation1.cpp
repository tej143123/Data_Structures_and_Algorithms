/* Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.*/

#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

int pascalTriangle(int r, int c){
    int element=ncr(r-1, c-1);
    return element;
}

int main(){
    int r=5;
    int c=3;
    int element=pascalTriangle(r, c);
    cout<<" The element at position(r, c) is : "<<element;
    return 0;
}


// TC---> O(C)
// SC---> O(1)
