#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main()
{
    int n=6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// TC---> O(N log N)
// SC---> O(1)