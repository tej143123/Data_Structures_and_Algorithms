#include<bits/stdc++.h>
using namespace std;


int longestConsecutiveSequence(vector<int>& arr, int n){
    int lonLength=1;
    int lastSmaller=INT_MIN;
    int cntCur=0;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastSmaller){
            cntCur=cntCur+1;
            lastSmaller=arr[i];
        }
        else if(arr[i]==lastSmaller){
            continue;
        }
        else{
            lastSmaller=arr[i];
            cntCur=1;
        }
        lonLength=max(lonLength, cntCur);
    } 
    return lonLength;
}

int main(){
    vector<int>arr={102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n=9;
    cout<<" The Longest Consecutive Length is : "<<longestConsecutiveSequence(arr, n);
    return 0;
}

// TC---> O(N log N)+ O(N)
// SC---> O(1)