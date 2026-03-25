#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int a[25][25];
int n,m;
ll k, ans;
map<ll,int> cnt[25];

void dfs1(int r, int c, int v, int step){
    if(a[r][c] == -1) return;

    v ^= a[r][c];
    
    if(!step){
        cnt[r][v]++;
        return;
    }

    dfs1(r+1, c, v, step-1);
    dfs1(r, c+1, v, step-1);
}

void dfs2(int r, int c, int v, int step){
    if(a[r][c] == -1) return;

    if(!step){
        ans += cnt[r][v];
        return;
    }
    
    v ^= a[r][c];
    dfs2(r-1, c, v, step-1);
    dfs2(r, c-1, v, step-1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    memset(a, -1, sizeof(a));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    int tot = (n+m-2);
    int mid = tot/2;
    dfs1(1, 1, 0, mid);
    dfs2(n, m, k, tot-mid);

    cout<<ans<<'\n';
}