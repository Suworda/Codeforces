#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[505];
int vis[505];
int from[505];
vector<int> cycle;
bool found_cycle;
pair<int,int> ban;

void dfs(int u){
    if(found_cycle) return;
    if(vis[u] == 1){
        found_cycle = 1;
        int x = from[u];
        cycle.push_back(u);
        while(x != u){
            cycle.push_back(x);
            x = from[x];
        }
        return;
    }
    if(vis[u] == 2) return;

    vis[u] = 1;
    for(int v: nxt[u]){
        from[v] = u;
        dfs(v);
    }
    vis[u] = 2;
}

bool dfs2(int u){
    if(vis[u] == 1){
        return false;
    }
    if(vis[u] == 2) return true;

    vis[u] = 1;
    for(int v: nxt[u]){
        from[v] = u;
        if(ban == make_pair(u,v)) continue;
        if(!dfs2(v)){
            vis[u] = 2;
            return false;
        }
    }
    vis[u] = 2;
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        nxt[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        dfs(i);
        if(found_cycle) break;
    }

    if(!found_cycle){
        cout<<"YES\n";
        return 0;
    }

    for(int i=0; i<cycle.size(); i++){
        bool ans = 1;
        ban = {cycle[(i+1)%cycle.size()], cycle[i]};
        memset(vis, 0, sizeof(vis));
        for(int u=1; u<=n; u++){
            if(!dfs2(u)){
                ans = 0;
            }
            
        }
        if(ans){
            cout << "YES\n";
            return 0;
        }
    }

    cout<<"NO\n";
}

/*
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[505];
int vis[505];
int parent_node[505]; // 麵包屑
vector<pair<int, int>> cycle_edges; // 直接存邊，不存點！

// 模組一：專心找第一個環，並把環的「邊」抽出來
bool find_cycle(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) { // 抓到 Back Edge 了！
            cycle_edges.push_back({u, v});
            int curr = u;
            while (curr != v) {
                cycle_edges.push_back({parent_node[curr], curr});
                curr = parent_node[curr];
            }
            return true; // 抓到就閃人
        }
        if (vis[v] == 0) {
            parent_node[v] = u;
            if (find_cycle(v)) return true;
        }
    }
    vis[u] = 2;
    return false;
}

// 模組二：專心檢查在「拔掉某條邊」的情況下，圖是不是 DAG
bool check_dag(int u, pair<int, int> ban_edge) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (u == ban_edge.first && v == ban_edge.second) continue; // 無情無視這條邊
        
        if (vis[v] == 1) return false; // 又撞到環了，失敗
        if (vis[v] == 0) {
            if (!check_dag(v, ban_edge)) return false;
        }
    }
    vis[u] = 2;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 1. 找嫌疑犯
    bool has_cycle = false;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && find_cycle(i)) {
            has_cycle = true;
            break;
        }
    }

    // 2. 本來就是 DAG？直接收工
    if (!has_cycle) {
        cout << "YES\n";
        return 0;
    }

    // 3. 輪流審問嫌疑犯
    for (auto ban_edge : cycle_edges) {
        memset(vis, 0, sizeof(vis)); // 每次檢查前重置狀態
        bool is_valid = true;
        
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0 && !check_dag(i, ban_edge)) {
                is_valid = false;
                break;
            }
        }
        
        if (is_valid) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
*/