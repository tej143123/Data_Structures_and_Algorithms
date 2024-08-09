#include<bits/stdc++.h>
using namespace std;

bool evenOrOdd(int num){
    if((num & 1)==0){
        return "even";
    }
    else{
        return "odd";
    }
}

int main(){
    int num = 10;
    if(evenOrOdd(num)){
        cout<<" Even ";
    }
    else{
        cout<<" Odd ";
    }
    return 0;
}


// TC---> O(1)
// SC---> O(1)