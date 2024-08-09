#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix){
    vector<int>ans;
    int n=matrix.size();
    int m=matrix[0].size();

    // Initialising the pointers required for traversal
    int right=m-1, bottom=n-1, left=0, top=0;

    while(top<=bottom && left<=right){
        // Printing the right elements
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Printing the bottom elements
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Printing the left elements
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Printing the top elements
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>matrix={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    vector<int>ans=spiralMatrix(matrix);
    cout<<" The Sprial Matrix is : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N*M)
// SC---> O(N*M)