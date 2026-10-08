#include<bits/stdc++.h>
using namespace std;

int constantWindow(vector<int>& nums, int n, int k){
    int currSum = 0;
    for(int i = 0; i < k; i++){
        currSum += nums[i];
    }
    int maxSum = currSum;
    int l = 0;
    int r = k - 1;
    while(r < n - 1){
        currSum -= nums[l];
        l++;
        r++;
        currSum += nums[r];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int longestSubarrayBruteForce(vector<int> nums, int n, int k){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int currSum = 0;
        for(int j = i; j < n; j++){
            currSum += nums[j];
            if(currSum <= k) maxLen = max(maxLen, j - i + 1);
            else if(currSum > k) break;
        }
    }
    return maxLen;
}

int longestSubarrayBetter(vector<int> nums, int n, int k){
    int currSum = 0;
    int l = 0, r = 0;
    int maxLen = 0;

    while(r < n){
        currSum += nums[r];
        while(currSum > k) currSum -= nums[l++];
        if(currSum <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int longestSubarrayOptimal(vector<int> nums, int n, int k){
    int l = 0, r = 0;
    int currSum = 0;
    int maxLen = 0;
    while(r < n){
        currSum += nums[r];
        if(currSum > k) currSum -= nums[l++];
        if(currSum <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main(){
    vector<int> nums1 = {-1, 2, 3, 3, 4, 5, -1};
    int n1 = nums1.size();
    int k1 = 4;

    cout<<endl<<"1. Constant window"<<endl<<endl;

    cout<<"Array : ";
    for(int i = 0; i < n1; i++) cout<<nums1[i]<<" ";
    cout<<endl;
    cout<<"K : "<<k1<<endl;

    cout<<"Q. maximum sum of k consecutive numbers : "<<constantWindow(nums1, n1, k1);
    cout<<endl<<endl;

    cout<<"2. Longest subarray where <condition>"<<endl<<endl;

    vector<int> nums2 = {5, 4, 7, 8, 1, 1, 1, 1, 1};
    int n2 = nums2.size();
    int k2 = 5;
    cout<<"Array : ";
    for(int i = 0; i < n2; i++) cout<<nums2[i]<<" ";
    cout<<endl;
    cout<<"k : "<<k2<<endl;

    cout<<"Q. Longest Subarray with sum <= k : "<<endl;
    cout<<"Brute Force : "<<longestSubarrayBruteForce(nums2, n2, k2)<<endl;
    cout<<"better : "<<longestSubarrayBetter(nums2, n2, k2)<<endl;
    cout<<"optimal : "<<longestSubarrayOptimal(nums2, n2, k2)<<endl;ma
}