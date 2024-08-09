#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr, int n){
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=neg.size();i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }
    return arr;
}

int main(){
    vector<int>arr{3,1,-2,-5,2,-4, -6, -7};
    int n=8;
    vector<int>ans=rearrangeArray(arr, n);
    cout<<" The Rearrange array elements of an array is : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


// TC---> O(N)+O(Min(pos.size(), neg.size()))+O(elementsLeft) ----> O(2N)---> Worst case
// SC---> O(N)