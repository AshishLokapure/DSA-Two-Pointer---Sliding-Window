#include<bits/stdc++.h>
using namespace std;

void bruteForce(string s, string t, int n, int m){
    int minLen = INT_MAX;
    int sIdx = -1;
    for(int i = 0; i < n; i++){
        int hash[256] = {0};
        int cnt = 0;
        for(int j = 0; j < m; j++) hash[t[j]]++;
        for(int j = i; j < n; j++){
            if(hash[s[j]] > 0) cnt++;
            hash[s[j]]--;
            if(cnt == m){
                minLen = min(minLen, j - i + 1);
                sIdx = i;
                break;
            }
        }
    }
    cout<<s.substr(sIdx, minLen);
}


void optimal(string s, string t, int n, int m) {
    int hash[256] = {0};
    int l = 0, r = 0, cnt = 0;
    int minLen = INT_MAX, sIndex = -1;
    for (int i = 0; i < m; i++) hash[t[i]]++;
    while (r < n) {
        if (hash[s[r]] > 0) cnt++;
        hash[s[r]]--;
        while (cnt == m) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0) cnt--;
            l++;
        }
        r++;
    }

    if (sIndex == -1) {
        cout << "";
    } else {
        cout << s.substr(sIndex, minLen);
    }
}


int main(){
    string s = "ddaaabbca";
    string t = "abc";
    int n = s.size();
    int m = t.size();

    cout<<"s : "<<s<<endl<<"t : "<<t<<endl;
    cout<<"Brute Force : ";
    bruteForce(s, t, n, m);
    cout<<endl;

    cout<<"optimal : ";
    optimal(s, t, n, m);
    cout<<endl;
}