#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int n,m;
    cin>>n>>m;
    int a[n], b[m];
    int d[n]={};

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);
    ll ans = 0;

    for(int i=0; i<n; i++){
        d[i] = abs(a[i] - b[m-1-i]);
    }

    for(int i=0; i<n; i++){
        d[i] = max(d[i], abs(a[i] - b[n-1-i]));
        ans += d[i];
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}