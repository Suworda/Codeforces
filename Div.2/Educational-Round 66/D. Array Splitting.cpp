#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    int sum[n+1]={};
    int ans=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ans+=a[i];
    }

    for(int i=n-1; i>=1; i--){
        sum[i]=sum[i+1]+a[i];
    }
    nth_element(sum+1 , sum+n-k , sum+n);

    for(int i=n-k+1; i<n; i++){
        ans+=sum[i];
    }

    cout<<ans<<'\n';
}
