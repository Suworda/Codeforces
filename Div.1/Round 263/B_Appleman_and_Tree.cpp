#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

const int M = 1000000007;
int n;
vector<int> nxt[100005];
bitset<100005> black;
ll dp[100005][2];

void dfs(int u, int pa) {
    if (black[u]) {
        dp[u][1] = 1; dp[u][0] = 0;
    } else {
        dp[u][0] = 1; dp[u][1] = 0;
    }

    for (int v : nxt[u]) {
        if (v == pa) continue;
        dfs(v, u);
        
        long long u0 = dp[u][0];
        long long u1 = dp[u][1];

        if(black[u]){
            dp[u][1] = u1*(dp[v][0] + dp[v][1]) %M;

        }else{
            dp[u][0] = u0*(dp[v][0] + dp[v][1]) %M;

            dp[u][1] = (u1*(dp[v][0] + dp[v][1]) + u0*(dp[v][1])) %M;

        }
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n-1; i++){
        int p;
        cin>>p;
        nxt[p].push_back(i);
    }

    for(int i=0; i<=n-1; i++){
        int x;
        cin>>x;
        if(x == 1) black[i] = 1;
    }

    dfs(0,-1);

    cout<<dp[0][1]<<'\n';

}