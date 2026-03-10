#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define INF 9e18

int n,k,x;
int a[5005];
ll dp[5005][5005];
int dq[5005];
int head=0, tail=-1;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k>>x;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    
    if(x < n/k){
        cout<<-1<<'\n';
        return 0;
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else dp[i][j] = -INF;
        }
    }
    for(int i=1; i<=k; i++) dp[i][1] = a[i];

    for(int j=1; j<=x; j++){
        head = 0, tail = -1;
        for(int i=1; i<=n; i++){
            if(head <= tail && dq[head] == i-k-1) head++;

            while(head <= tail && dp[i-1][j-1] >= dp[dq[tail]][j-1]){
                tail--;
            }
            dq[++tail] = i-1;

            dp[i][j] = dp[dq[head]][j-1] + a[i];

        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=x; j++){
    //         printf("%6d ", dp[i][j]);
    //     }
    //     cout<<'\n';
    // }
    
    ll ans = 0;
    for(int i=n-k+1; i<=n; i++) ans = max(ans, dp[i][x]);

    cout<<ans<<'\n';
    
}
