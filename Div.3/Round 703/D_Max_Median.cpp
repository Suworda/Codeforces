#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];

bool valid(int v){
    int b[n+5]={};
    int sum[n+5]={};
    for(int i=1; i<=n; i++){
        if(a[i] < v) b[i] = -1;
        else b[i] = 1;
    }

    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + b[i];

    int mi = 2e9;
    for(int i=k; i<=n; i++){
        int cur = sum[i];
        if(sum[i-k] < mi){
            mi = sum[i-k];
        }

        if(cur - mi > 0) return true;
    }

    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    int l=0, r=n, ans=-1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    cout<<ans<<'\n';

}