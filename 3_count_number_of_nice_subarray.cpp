#include<bits/stdc++.h>
using namespace std;

int niceSubarray(vector<int>& nums, int n, int k){
    int l = 0, r = 0, cnt = 0, oddCnt = 0;
    while(r < n){
        if(nums[r] % 2 != 0) oddCnt++;
        while(oddCnt > k){
            if(nums[l] % 2 != 0) oddCnt--;
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1, 1, 2, 1, 1};
    int n = nums.size();
    int k = 3;

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl<<"K : "<<k<<endl;

    cout<<"Q. Number Nice Subarray : ";
    cout<<niceSubarray(nums, n, k) - niceSubarray(nums, n, k - 1);
}