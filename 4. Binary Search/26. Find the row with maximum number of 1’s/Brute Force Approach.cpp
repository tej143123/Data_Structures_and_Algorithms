#include<bits/stdc++.h>
using namespace std;

int findRowWithMax1s(vector<vector<int>>& mat, int n, int m){
    int maxCnt = 0, ind = -1;
    for(int i=0;i<n;i++){
        int cntRow = 0;
        for(int j=0;j<m;j++){
            cntRow += mat[i][j];
        }
        if(cntRow > maxCnt){
            maxCnt = cntRow;
            ind = i;
        }
    }
    return ind;
}


int main(){
    vector<vector<int>> mat = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3;
    int m = 3;
    int ans = findRowWithMax1s(mat, n, m);
    cout<<" The row with max number of 1's is : "<<ans<<endl;
    return 0;
}


// TC---> O(N * M)
// SC---> O(1)