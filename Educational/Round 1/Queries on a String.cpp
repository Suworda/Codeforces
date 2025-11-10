#include <bits/stdc++.h>
using namespace std;
string s;

void sol(){
    int l,r,k;
    cin>>l>>r>>k;
    l--; k%=(r-l);
    rotate(s.begin()+l, s.begin()+r-k, s.begin()+r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>s>>m;
    while(m--){
        sol();
    }
    cout<<s<<'\n';
}
