#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int>& nums, int n, int k){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int zeroCount = 0;
        for(int j = i; j < n; j++){
            if(nums[j] == 0) zeroCount++;
            else if(zeroCount <= k) maxLen = max(maxLen, j - i + 1);
            else break;
        }
    }
    cout<<maxLen;
}

void optimal1(vector<int>& nums, int n, int k){
    int maxLen = 0;
    int l = 0, r = 0;
    int zeros = 0;
    while(r < n){
        if(nums[r] == 0) zeros++;
        while(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

void optimal2(vector<int>& nums, int n, int k){
    int maxLen = 0;
    int l = 0, r = 0;
    int zeros = 0;
    while(r < n){
        if(nums[r] == 0) zeros++;
        if(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

int main(){
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int n = nums.size();
    int k = 3;

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;
    cout<<"K : "<<k<<endl;

    cout<<"Brute Force : ";
    bruteForce(nums, n, k);
    cout<<endl;

    cout<<"Optimal 1 : ";
    optimal1(nums, n, k);
    cout<<endl;

    cout<<"Optimal 2 : ";
    optimal2(nums, n, k);
    cout<<endl;
}