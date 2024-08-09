#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& arr1, vector<int>& arr2, int n1, int n2){
    int left = 0;
    int right = 0;
    // to store all the elements from arr1 and arr2
    vector<int>arr3;
    while(left < n1 && right < n2){
        if(arr1[left] <= arr2[right]){
            arr3.push_back(arr1[left]);
            left++;
        }
        else{
            arr3.push_back(arr2[right]);
            right++;
        }
    }

    // copy the left-out elements
    while(left < n1){
        arr3.push_back(arr1[left]);
        left++;
    }

    while(right < n2){
        arr3.push_back(arr2[right]);
        right++;
    }
    // find the median
    int n = n1 + n2;
    // if size of arr3 is odd
    if(n % 2 == 1) return arr3[n / 2];
    // if size of arr3 is even
    double median = (double (arr3[n / 2]) + double (arr3[(n / 2) - 1])) / 2.0 ;
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
// SC---> O(n1 + n2)