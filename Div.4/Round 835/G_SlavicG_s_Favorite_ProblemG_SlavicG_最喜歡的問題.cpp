#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,a,b;
vector<pair<int,int>> nxt[100005];
set<int> st;
bool found;

void dfs_b(int u, int pa, int val){
    if(u != b) st.insert(val);
    
    for(auto [v,w]: nxt[u]){
        if(v == pa) continue;
        dfs_b(v,u,val^w);
    }
}

void dfs_a(int u, int pa, int val){
    if(u == b){
        if(val == 0) found = 1;
        return;
    }else{
        if(st.count(val)) found = 1;

    }
    
    for(auto [v,w]: nxt[u]){
        if(v == pa) continue;
        dfs_a(v,u,val^w);
    }
}

void sol(){
    cin>>n>>a>>b;
    st.clear();
    for(int i=1; i<=n; i++) nxt[i].clear();
    found=0;

    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        nxt[u].push_back({v,w});
        nxt[v].push_back({u,w});
    }

    dfs_b(b,0,0);
    // for(auto x: st) cerr<<x<<' ';
    // cerr<<"\n\n";
    dfs_a(a,0,0);

    cout<<(found ? "YES" : "NO")<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}