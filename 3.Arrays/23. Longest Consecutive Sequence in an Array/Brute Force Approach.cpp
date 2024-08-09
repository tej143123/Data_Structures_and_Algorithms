#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int target, int n){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}
int longestConsecutiveSequence(vector<int>& arr, int n){
    int longestLength=1;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int cnt=1;
        while(linearSearch(arr, x+1, n)==true){
            x=x+1;
            cnt=cnt+1;
        }
        longestLength=max(longestLength, cnt);
    }
    return longestLength;
}

int main(){
    vector<int>arr={102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n=9;
    cout<<" The Longest Consecutive Length is : "<<longestConsecutiveSequence(arr, n);
    return 0;
}

// TC---> O(N^2)
// SC---> O(1)