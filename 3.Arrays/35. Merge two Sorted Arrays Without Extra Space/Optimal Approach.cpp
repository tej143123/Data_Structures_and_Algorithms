#include<bits/stdc++.h>
using namespace std;

void mergeTwoSortedArrays(vector<long long>& arr1, vector<long long>& arr2, int n, int m){
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
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


// TC---> O(min(N, M)) + O(N log N) + O(M log M)
// SC---> O(1)