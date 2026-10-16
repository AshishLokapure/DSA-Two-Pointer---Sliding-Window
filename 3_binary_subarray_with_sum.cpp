#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int n, int goal){
    int l = 0, r = 0, cnt = 0, sum = 0;
    while(r < n){
        sum += nums[r];
        while(sum > goal) sum -= nums[l++];
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int n = nums.size();
    int goal = 2;

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl<<"Goal : "<<goal<<endl;

    cout<<"Q. Number of Subarray sum == goal : ";
    cout<<subarraySum(nums, n, goal) - subarraySum(nums, n, goal - 1);
}