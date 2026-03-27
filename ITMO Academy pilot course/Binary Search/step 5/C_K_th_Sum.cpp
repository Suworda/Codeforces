#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
ll k;
int a[100005], b[100005];

bool valid(int m){
    int rst = 0;
    for(int i=0, j=n; i<n; i++){
        while(j-1 >= 0 && a[i] + b[j-1] > m) j--;
        rst += j;
    }

    return rst >= k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+n);

    ll l=0, r=2e9, ans=-1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout<<ans<<'\n';
}