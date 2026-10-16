#include<bits/stdc++.h>
using namespace std;

void bruteForce(string s, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int hash[3] = {0};
        for(int j = i; j < n; j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3) {
                cnt += (n - j);
                break;
            }
        }
    }
    cout<<cnt;
}

void optimal(string s, int n){
    int cnt = 0;
    int hash[3] = {-1, -1, -1};
    for(int i = 0; i < n; i++){
        hash[s[i] - 'a'] = i;
        cnt += 1 + min({hash[0], hash[1], hash[2]});
    }
    cout<<cnt;
}

int main(){
    string s = "bbacba";
    int n = s.size();

    cout<<"S : "<<s<<endl;
    cout<<"Brute Force : ";
    bruteForce(s, n);
    cout<<endl;

    cout<<"optimal : ";
    optimal(s, n);
    cout<<endl;
}