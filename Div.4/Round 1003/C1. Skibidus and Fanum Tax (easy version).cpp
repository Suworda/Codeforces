#include <bits/stdc++.h>
using namespace std;
int n,m;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    int sum=0;
    int mi=0;
    int ans=-2e9;

    for(int d=0; d<m; d++){
        sum=0;
        mi=0;
        for(int th=0; th+d<m && th<n ; th++){
            sum+=a[th]*b[d+th];
            ans=max(ans,sum-mi);
            mi=min(mi,sum);
        }
//        cout<<ans<<'\n';
    }
    for(int d=0; d<n; d++){
        sum=0;
        mi=0;
        for(int th=0; th+d<n && th<m ; th++){
            sum+=a[d+th]*b[th];
            ans=max(ans,sum-mi);
            //cout<<a[d+th]<<' '<<b[th]<<'\n';
            mi=min(mi,sum);
        }
//        cout<<ans<<'\n';
    }

    reverse(a,a+n);

    for(int d=0; d<m; d++){
        sum=0;
        mi=0;
        for(int th=0; th+d<m && th<n ; th++){
            sum+=a[th]*b[d+th];
            ans=max(ans,sum-mi);
            mi=min(mi,sum);
        }
//        cout<<ans<<'\n';
    }
    for(int d=0; d<n; d++){
        sum=0;
        mi=0;
        for(int th=0; th+d<n && th<m ; th++){
            sum+=a[d+th]*b[th];
            ans=max(ans,sum-mi);
            mi=min(mi,sum);
        }
//        cout<<ans<<'\n';
    }

    cout<<ans<<'\n';
}

/*
5 5
1 2 3 4 5
6 7 8 9 10
*/

