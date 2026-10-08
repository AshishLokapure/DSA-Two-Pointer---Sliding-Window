#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int n = nums.size();
    int k = 4;

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;

    int lSum = 0, rSum = 0;
    for(int i = 0; i < k ; i++){
        lSum += nums[i];
    }
    int maxSum = lSum;
    int r = n - 1;
    for(int i = k - 1; i >= 0; i--){
        lSum -= nums[i];
        rSum += nums[r--];
        maxSum = max(maxSum, (lSum + rSum));
    }
    cout<<"Ans : "<<maxSum;

}