#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& weights){
    int n = weights.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}

int findSum(vector<int>& weights){
    int n = weights.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += weights[i];
    }
    return sum;
}

int findDays(vector<int>& weights, int cap){
    // First Day
    int day = 1;
    int load = 0; // Initial load
    int n = weights.size();
    for(int i=0;i<n;i++){
        if(load + weights[i] <= cap){
            load += weights[i]; // load the weight on the same day
        }
        else{
            day = day + 1; // move to next day
            load = weights[i]; // load the weight
        }
    }
    return day; // returning the days to ship packages for the capacity
}
int findMinimumCapacity(vector<int>& weigths, int days){
    int sum = findSum(weigths);
    int maxi = findMax(weigths);
    for(int cap=maxi;cap<=sum;cap++){
        int daysReq = findDays(weigths, cap);
        if(daysReq <= days){
            return cap;
        }
    }
    return -1;
}


int main(){
    vector<int>weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int leastCapacity = findMinimumCapacity(weights, days);
    cout<<" The least capacity should required to ship packages within D days is : "<<leastCapacity<<endl;
    return 0;
}


// TC---> O(((Sum - Maxi) + 1) * N)
// SC---> O(1)