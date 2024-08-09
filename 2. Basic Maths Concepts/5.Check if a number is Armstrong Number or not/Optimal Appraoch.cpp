#include<bits/stdc++.h>
using namespace std;

int countDigits(int number){
    int cnt = 0;
    while(number > 0){
        cnt++;
        number = number / 10;
    }
    return cnt;
}

long long power(int lastDigit, int total_digits){
    long long ans = 1;
    for(int i=1;i<=total_digits;i++){
        ans *= lastDigit;
    }
    return ans;
}

bool isArmstrong(int number){
    int total_digits = countDigits(number);
    int sum = 0, temp = number;
    while(number > 0){
        int lastDigit = number % 10;
        int ans = power(lastDigit, total_digits);
        sum += ans;
        number = number / 10;
    }
    if(sum == temp) return true;
    return false;
}


int main(){
    int number;
    cin >> number;
    bool ans = isArmstrong(number);
    if(ans){
        cout<<" Yes, The given number is Armstrong Number"<<endl;
    }
    else{
        cout<<" NO, The given number is not an Armstrong Number"<<endl;
    }
    return 0;
}

// TC---> O(log10(n)) * O(log10(n))
// SC---> O(1)