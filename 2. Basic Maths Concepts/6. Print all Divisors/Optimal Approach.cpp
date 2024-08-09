#include<bits/stdc++.h>
using namespace std;

vector<int> FindDivisors(int number){
    // for storing the divisors
    vector<int>temp;
    for(int i=1;i*i<=number;i++){
        // if i completely divides number
        // it means --> remainder has to be zero
        if((number % i) == 0){
            temp.push_back(i);
            if((number / i) != i){
                temp.push_back(number / i);
            }
        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}


int main(){
    int number;
    cin >> number;
    vector<int> ans = FindDivisors(number);
    cout<<" The divisors of given number are : ";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(Sqrt(N)) + O(n log n) ---> n is the number of factors
// SC---> O(n) ---> n is the number of factors