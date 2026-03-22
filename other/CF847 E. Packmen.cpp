#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;

vector<int> star, pac;

bool ok(int p, int l, int r, int m){
    int sz = star.size();
    if(l > r || l >= sz || r >= sz) return false;
    l = star[l], r = star[r];

    if(r < p) return p - l <= m;
    if(p < l) return r - p <= m;
    return min(abs(p-l), abs(p-r)) + (r-l) <= m; 
}

bool valid(int m){
    int sz = star.size(), l = 0, r = 0;
    for(int p: pac){
        while(ok(p,l,r,m)){
            r++;
        }
        l = r;
        if(l == sz) return true;
    }

    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;

    for(int i=0; i<n; i++){
        if(s[i] == '*') star.push_back(i);
        if(s[i] == 'P') pac.push_back(i);
    }

    int l=0, r=n*2, ans=-1;
    while(l <= r){
        int m =(l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout<<ans<<'\n';

}