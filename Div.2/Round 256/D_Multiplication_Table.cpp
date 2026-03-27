#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,k;

bool valid(int x){
    ll rst = 0;
    for(int i=1; i<=n; i++){
        rst += min(m, x/i);
    }
    return rst >= k;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    ll l=0, r=1e15, ans=-1;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<'\n';

}