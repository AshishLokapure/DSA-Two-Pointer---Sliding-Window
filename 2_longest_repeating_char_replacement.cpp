#include<bits/stdc++.h>
using namespace std;

void bruteForce(string s, int n, int k){
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int hash[26] = {0};
        int maxF = 0;
        for(int j = i; j < n; j++){
            hash[s[j] - 'A']++;
            maxF = max(maxF, hash[s[j] - 'A']);
            int rem = (j - i + 1) - maxF;
            if(rem <= k) maxLen = max(maxLen, j - i + 1);
            else break;
        }
    }
    cout<<maxLen;
}

void optimal1(string s, int n, int k){
    int hash[26] = {0};
    int l = 0, r = 0;
    int maxLen = 0, maxF = 0;
    while(r < n){
        hash[s[r] - 'A']++;
        maxF = max(maxF, hash[s[r] - 'A']);
        int rem = (r - l + 1) - maxF;
        if(rem > k){
            while(rem > k){
                hash[s[l] - 'A']--;
                maxF = 0;
                for(int i = 0; i < 26; i++) maxF = max(maxF, hash[i]);
                rem = (r - l + 1) - maxF;
                l++;
            }
        }
        if(rem <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

void optimal2(string s, int n, int k){
    int hash[26] = {0};
    int l = 0, r = 0;
    int maxLen = 0, maxF = 0;
    while(r < n){
        hash[s[r] - 'A']++;
        maxF = max(maxF, hash[s[r] - 'A']);
        int rem = (r - l + 1) - maxF;
        if(rem > k){
            hash[s[l] - 'A']--;
            maxF = 0;
            rem = (r - l + 1) - maxF;                
            l++;    
        }
        if(rem <= k) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    cout<<maxLen;
}

int main(){
    string s = "AABABBA";
    int n = s.size();
    int k = 2;

    cout<<"Array : "<<s<<endl;
    cout<<"k : "<<k<<endl;

    cout<<"Brute Force : ";
    bruteForce(s, n, k);
    cout<<endl;

    cout<<"optimal 1 : ";
    optimal1(s, n, k);
    cout<<endl;

    cout<<"optimal 2 : ";
    optimal2(s, n, k);
    cout<<endl;
}