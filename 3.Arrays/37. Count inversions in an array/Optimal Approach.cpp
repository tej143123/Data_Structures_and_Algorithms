#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high){
    int right = mid+1;
    int left = low;
    vector<int>temp;
    int cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid){
            temp.push_back(arr[left]);
            left++;
    }

    while(right <= high){
            temp.push_back(arr[right]);
            right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high)/2;
    cnt +=mergeSort(arr, low, mid); // left half
    cnt +=mergeSort(arr, mid+1, high); // right half
    cnt +=merge(arr, low, mid, high); // merging two sorted halves
    return cnt;
}

int countInversions(vector<int>& arr, int n){
    return mergeSort(arr, 0, n-1);
}
int main(){
    vector<int>arr={5, 3, 2, 4, 1};
    int n=5;
    cout<<" The number of inversions are : "<<countInversions(arr, n)<<endl;
    return 0;
}


// TC---> O(N log N)
// SC---> O(N)