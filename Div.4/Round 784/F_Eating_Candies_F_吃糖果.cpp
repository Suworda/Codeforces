#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[200005];
void sol(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int l = -1, r = n;
    int lsum = 0, rsum = 0;
    int ans = 0;
    while(l < r){
        if(lsum < rsum) lsum += a[++l];
        else if(rsum < lsum) rsum += a[--r];

        
        if(lsum == rsum){
            ans = n-r+1+l;
            lsum += a[++l];
            rsum += a[--r];
        }
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