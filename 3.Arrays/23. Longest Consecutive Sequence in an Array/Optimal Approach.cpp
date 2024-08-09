#include<bits/stdc++.h>
using namespace std;


int longestConsecutiveSequence(vector<int>& arr, int n){
    unordered_set<int>st;
    int longest=1;
    if(n==0) return 0;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int cnt=1;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest, cnt);
        }
    }
    return longest;
}


int main(){
    vector<int>arr={102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n=9;
    cout<<" The Longest Consecutive Length is : "<<longestConsecutiveSequence(arr, n);
    return 0;
}

// TC---> O(N)+O(2*N)
// SC---> O(N)