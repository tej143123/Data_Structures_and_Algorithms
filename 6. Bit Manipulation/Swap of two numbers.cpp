#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int a = 5, b= 7;
    swap(a, b);
    cout<<"After Swapping of two numbers : "<< a <<" , "<< b <<endl;
    return 0;
}


// TC---> O(1)
// SC---> O(1)