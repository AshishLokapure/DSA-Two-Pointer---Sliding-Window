#include<bits/stdc++.h>
using namespace std;

void bruteForce(string s, int n, int k){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        map<char, int> mpp;
        for(int j = i; j < n; j++){
            mpp[s[j]]++;
            if(mpp.size() <= k) maxLen = max(maxLen, j - i + 1);
            else break;
        }
    }
    cout<<maxLen;
}

void optimal1(string s, int n, int k){
    map<char, int> mpp;
    int l = 0, r = 0;
    int maxLen = 0;
    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
        }
        if(mpp.size() <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

void optimal2(string s, int n, int k){
    map<char, int> mpp;
    int l = 0, r = 0;
    int maxLen = 0;
    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size() <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

int main(){
    string s = "aababbcaacc";
    int n = s.size();
    int k = 2;

    cout<<"String : "<<s<<endl;
    cout<<"K : "<<k<<endl;

    cout<<"Brute Force : ";
    bruteForce(s, n, k);
    cout<<endl;

    cout<<"Optimal 1 : ";
    optimal1(s, n, k);
    cout<<endl;

    cout<<"optimal 2 : ";
    optimal2(s, n, k);
    cout<<endl;
}