#include<bits/stdc++.h>
using namespace std;

void bruteForce(string s, int n){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int hashSet[256] = {0};
        for(int j = i; j < n; j++){
            if(hashSet[s[j]] == 1) break;
            maxLen = max(maxLen, (j - i + 1));
            hashSet[s[j]] = 1;
        }
    }
    cout<<maxLen;
}   

void optimal(string s, int n){
    int hashSet[256] = {-1};
    int l = 0;
    int r = 0;
    int maxLen = 0;
    while(r < n){
        if(hashSet[s[r]] != -1){
            if(hashSet[s[r]] >= l) l = hashSet[s[r]] + 1;
        }
        maxLen = max(maxLen, r - l + 1);
        hashSet[s[r]] = r;
        r++;
    }
    cout<<maxLen;
}

int main(){
    string s = "cadbzabcd";
    int n = s.size();

    cout<<"S : ";
    for(int i = 0; i < n; i++) cout<<s[i]<<" ";
    cout<<endl;

    cout<<"Brute Force : ";
    bruteForce(s, n);
    cout<<endl;

    cout<<"optimal : ";
    optimal(s, n);
    cout<<endl;
}