#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int>& nums, int n, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        unordered_map<int, int> mpp;
        for(int j = i; j < n; j++){
            mpp[nums[j]]++;
            if(mpp.size() == k) cnt++;
            else if(mpp.size() > k) break;
        }
    }
    cout<<cnt;
}

int optimal(vector<int>& nums, int n, int k){
    int l = 0, r = 0, cnt = 0;
    unordered_map<int, int> mpp;
    while(r < n){
        mpp[nums[r]]++;
        while(mpp.size() > k){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int main(){
    vector<int> nums = {2, 1, 1, 1, 3, 4, 3, 2};
    int n = nums.size();
    int k = 3;

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl<<"k : "<<k<<endl;

    cout<<"brute Force : ";
    bruteForce(nums, n, k);
    cout<<endl;

    cout<<"optimal : ";
    cout<<optimal(nums, n, k) - optimal(nums, n, k - 1);
    cout<<endl;
}