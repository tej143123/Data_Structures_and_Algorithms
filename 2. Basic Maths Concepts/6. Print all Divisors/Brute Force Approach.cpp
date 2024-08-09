#include<bits/stdc++.h>
using namespace std;

vector<int> FindDivisors(int number){
    // for storing the divisors
    vector<int>temp;
    for(int i=1;i<=number;i++){
        // if i completely divides number
        // it means --> remainder has to be zero
        if((number % i) == 0){
            temp.push_back(i);
        }
        else{
            continue;
        }
    }
    return temp;
}


int main(){
    int number;
    cin >> number;
    vector<int> ans = FindDivisors(number);
    cout<<" The divisors of given number are : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)