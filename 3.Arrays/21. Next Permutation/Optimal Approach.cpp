#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& arr, int n){
    int ind=-1;
    // 1. Finding the break point(Longer Prefix Match)
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    // If Breakpoint doesn't exist then reverse the whole array
    if(ind==-1) reverse(arr.begin(), arr.end());

    // 2. Find someone greater than ind but the smallest one
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            // Because of we need greater permutation but slightly greater and the elements from the last upto ind+1 are in increasing order even we swap
            swap(arr[i], arr[ind]);
            break;
        }
    }
    // 3. Try to place the rest of the elements from ind+1 to the end of an array 
    reverse(arr.begin()+ind+1, arr.end());
    return arr;
}

int main(){
    vector<int>arr={2,1,5,4,3,0,0};
    int n=7;
    vector<int>ans=nextPermutation(arr, n);
    cout<<" The Next Permutation is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;   
}

// TC---> O(3N) (Worst Case) ---> nearly(O(N))
// SC---> O(N)(for modifying the array in order to return the ans)
// EXtra Space ---> O(1)