#include<bits/stdc++.h>
using namespace std;

void mergeTwoSortedArrays(vector<long long>& arr1, vector<long long>& arr2, int n, int m){
    vector<long long>arr3(n+m, 0);
    int left = 0;
    int right= 0;
    int index = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++, index++;
        }
        else{
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    while(left < n){
        arr3[index] = arr1[left];
        left++, index++;
    }

    while(right < m){
        arr3[index] = arr2[right];
        right++, index++;
    }

    for(int i=0;i<n+m;i++){
        if(i < n){
            arr1[i] = arr3[i];
        }
        else{
            arr2[i-n] = arr3[i];
        }
    }
}

int main(){
    vector<long long>arr1={1, 3, 5, 7};
    vector<long long>arr2={0, 2, 6, 8, 9};
    int n=4;
    int m=5;
    mergeTwoSortedArrays(arr1, arr2, n, m);
    cout<<" The merged arrays are : "<<endl;
    cout<<" arr1[] = [";
    for(auto it : arr1){
        cout<<it<<" ";
    }
    cout<<"]"<<endl;
    cout<<" arr2[] = [";
    for(auto it : arr2){
        cout<<it<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}

// TC---> O(N + M) + O(N + M)
// SC---> O(N + M)