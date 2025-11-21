#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int x;
    map<int,int> cnt;
    long long ans=0;
    for(int i=1; i<=n; i++){
        cin>>x;
        ans += cnt[x-i]++;
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
