#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int>& books, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, books[i]);
    }
    return maxi;
}

int findSum(vector<int>& books, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += books[i];
    }
    return sum;
}

int noOfStudents(vector<int>& books, int pages, int n){
    int student = 1;
    int pagesStudent = 0;
    for(int i=0;i<n;i++){
        if(pagesStudent + books[i] <= pages){
            pagesStudent += books[i];
        }
        else{
            student++;
            pagesStudent = books[i];
        }
    }
    return student;
}
int allocateBooks(vector<int>& books, int m, int n){
    int low = findMax(books, n);
    int high = findSum(books, n);
    int ans = -1;
    if(m > n) return -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int cntStudents = noOfStudents(books, mid, n);
        if(cntStudents == m){
            ans = mid;
            high = mid - 1;
        }
        else if(cntStudents < m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> books = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = allocateBooks(books, m, n);
    cout<<" The maximum number of pages allocated to a student is minimum is : "<<ans<<endl;
    return 0;
}


// TC---> O(N * (log(Sum(books[]) - Max(books[]) + 1)))
// SC---> O(1)