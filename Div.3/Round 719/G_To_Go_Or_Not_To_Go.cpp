#include <bits/stdc++.h>
using namespace std;

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int n,m,w;
int a[2005][2005];
long long cost[2005][2005][2];

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cost[i][j][0] = 8e18;
            cost[i][j][1] = 8e18;
        }
    }
}

bool valid(int r, int c){
    return r>=1 && r<=n && c>=1 && c<=m && a[r][c] != -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>n>>m>>w;
    init();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    queue<pair<int,int>> q1,q2;
    long long rst1=4e18 , rst2=4e18;
    q1.push({1,1});
    cost[1][1][0] = 0;
    if(a[1][1] > 0 ) rst1 = a[1][1];

    while(!q1.empty()){
        auto [r,c] = q1.front();
        q1.pop();

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc) && cost[nr][nc][0] == 8e18){
                q1.push({nr,nc});
                cost[nr][nc][0] = cost[r][c][0]+w;

                if(a[nr][nc] > 0){
                    rst1 = min(rst1 , cost[r][c][0] + a[nr][nc] + w);
                }
            }
        }
    }

    q2.push({n,m});
    cost[n][m][1]=0;
    if(a[n][m] > 0 ) rst2 = a[n][m];

    while(!q2.empty()){
        auto [r,c] = q2.front();
        q2.pop();

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc) && cost[nr][nc][1] == 8e18){
                q2.push({nr,nc});
                cost[nr][nc][1] = cost[r][c][1]+w;
            }

            if(a[nr][nc] > 0){
                rst2 = min(rst2 , cost[r][c][1] + a[nr][nc] + w);
            }
        }
    }

    //cout<<rst1<<' '<<rst2<<'\n';

    long long ans = min(cost[n][m][0] , rst1+rst2);

    if(ans > 1e18) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         printf("%20lld " , cost[i][j][1]);
    //     }
    //     cout<<'\n';
    // }

}