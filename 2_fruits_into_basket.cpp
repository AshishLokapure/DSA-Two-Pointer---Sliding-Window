#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> nums, int n){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        set<int> st;
        for(int j = i; j < n; j++){
            st.insert(nums[j]);
            if(st.size() <= 2) maxLen = max(maxLen, j - i + 1);
            else break;
        }
    }
    cout<<maxLen;
}

void optimal1(vector<int> nums, int n){
    map<int, int> mpp;
    int l = 0, r = 0;
    int maxLen = 0;
    while(r < n){
        mpp[nums[r]]++;
        if(mpp.size() > 2){
            while(mpp.size() > 2){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
        }
        if(mpp.size() <= 2) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

void optimal2(vector<int> nums, int n){
    map<int, int> mpp;
    int r = 0, l = 0;
    int maxLen = 0;
    while(r < n){
        mpp[nums[r]]++;
        if(mpp.size() > 2){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size() <= 2) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

int main(){
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int n = nums.size();

    cout<<"Array : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;

    cout<<"brute force : ";
    bruteForce(nums, n);
    cout<<endl;

    cout<<"optimal : ";
    optimal1(nums, n);
    cout<<endl;

    cout<<"optimal : ";
    optimal2(nums, n);
    cout<<endl;
}