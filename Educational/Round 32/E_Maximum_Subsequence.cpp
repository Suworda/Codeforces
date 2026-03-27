#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[35];
vector<int> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];

    int mid = n/2;
    for(int i=0; i<(1<<mid); i++){
        ll rst = 0;
        for(int j=0; j<mid; j++){
            if((i>>j) & 1) rst += a[j];
        }
        v.push_back(rst%m);
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for(int i=0; i<(1<<(n-mid)); i++){
        int rst = 0;
        for(int j=0; j<n-mid; j++){
            if((i>>j) & 1) rst += a[j+mid];
        }
        rst %= m;
        auto it = lower_bound(v.begin(), v.end(), m - rst);
        if(it != v.begin()) it--;
        ans = max(ans, (*it + rst)%m);

    }

    cout<<ans<<'\n';

}