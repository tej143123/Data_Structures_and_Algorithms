#include<bits/stdc++.h>
using namespace std;

void TOH(int n, int src, int aux, int dest, vector<vector<int>>& ans){
    // Base Case
    if(n == 1){
        ans.push_back({src, dest});
        return;
    }
    TOH(n - 1, src, dest, aux, ans);
    TOH(1, src, aux, dest, ans);
    TOH(n - 1, aux, src, dest, ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    int src = 1, aux = 2, dest = 3;
    vector<vector<int>>ans;
    TOH(n, src, aux, dest, ans);
    return ans;
}