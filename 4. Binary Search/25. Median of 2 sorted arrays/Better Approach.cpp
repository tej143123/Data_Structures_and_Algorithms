#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& arr1, vector<int>& arr2, int n1, int n2){
    int left = 0;
    int right = 0;
    int n = n1 + n2;
    int ind2 = (n / 2);
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1ele = -1, ind2ele = -1;
    while(left < n1 && right < n2){
        if(arr1[left] <= arr2[right]){
            if(cnt == ind1) ind1ele = arr1[left];
            if(cnt == ind2) ind2ele = arr1[left];
            cnt++;
            left++;
        }
        else{
            if(cnt == ind1) ind1ele = arr2[right];
            if(cnt == ind2) ind2ele = arr2[right];
            cnt++;
            right++;
        }
    }

    while(left < n1){
        if(cnt == ind1) ind1ele = arr1[left];
        if(cnt == ind2) ind2ele = arr1[left];
        cnt++;
        left++;
    }

    while(right < n2){
        if(cnt == ind1) ind1ele = arr2[right];
        if(cnt == ind2) ind2ele = arr2[right];
        cnt++;
        right++;
    }

    if((n % 2) == 1) return ind2ele;

    double median = (double(ind1ele + ind2ele)) / 2.0;
    return median;
}


int main(){
    vector<int>arr1 = {1, 3, 4, 7, 10, 12};
    vector<int>arr2 = {2, 3, 6, 15};
    int n1 = 6, n2 = 4;
    double median = findMedian(arr1, arr2, n1, n2);
    cout<<" The median of two sorted arrays is : "<<median<<endl;
    return 0;
}


// TC---> O(n1 + n2)
// SC---> O(1)