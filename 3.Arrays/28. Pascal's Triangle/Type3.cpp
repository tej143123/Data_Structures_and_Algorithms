/* Given the row number n. Print the n-th row of Pascal’s triangle. */

#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    // Printing first element
    ansRow.push_back(ans);  

    // Printing the rest of the part, i--->col
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;  
}

vector<vector<int>>pascalTriangle(int N){
    vector<vector<int>>ans;
    for(int row=1;row<=N;row++){
        ans.push_back(generateRow(row));
    }
    return ans;
}


int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    return 0;
}

// TC---> O(N * N)
// SC---> O(1)