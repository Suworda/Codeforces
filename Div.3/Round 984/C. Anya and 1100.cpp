#include <bits/stdc++.h>
using namespace std;


void sol(){
    string s;
    cin>>s;
    int n=s.size();
    int q;
    cin>>q;
    int cnt=0;
    for(int i=0; i<=n-4; i++){
        cnt+=(s.substr(i,4)=="1100");
    }

    int p;
    char v;
    while(q--){
        cin>>p>>v; p--;
        for(int i=max(0,p-3); i<=min(p,n-4); i++){
            cnt-=(s.substr(i,4)=="1100");
        }
        s[p]=v;
        for(int i=max(0,p-3); i<=min(p,n-4); i++){
            cnt+=(s.substr(i,4)=="1100");
        }

        cout<<(cnt ? "YES" :"NO")<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
