#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>& stalls, int dist, int cows){
    int n = stalls.size();
    int cntCows = 1;
    int lastCoordinate = stalls[0];
    for(int i=1;i<n;i++){
        if((stalls[i] - lastCoordinate) >= dist){
            cntCows++;
            lastCoordinate = stalls[i];
        }
    }
    if(cntCows >= cows) return true;
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows){
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = stalls[n - 1] - stalls[0]; // maximum distance possible
    while(low <= high){
        int mid = (low + high) / 2;
        if(canWePlace(stalls, mid, cows) == true){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int>stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int ans = aggressiveCows(stalls, cows);
    cout<<" The maximum possible minimum distance is : "<<ans<<endl;
    return 0;
}


// TC---> O(N log N) + O(N * log (max(stalls) - min(stalls))) 
// SC---> O(1)