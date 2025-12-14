#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005][1005];
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int dis[1005][1005][2];

bool valid(int r, int c){
    return r>=1 && r<=n && c>=1 && c<=n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    queue<array<int, 3>> que;
    que.push({1,1,0});
    que.push({1,1,1});
    dis[1][1][0] = dis[1][1][1] = 1;

    while(!que.empty()){
        auto [r,c,ty] = que.front();
        que.pop();

        if(r == n && c == n){
            cout<<dis[r][c][ty]<<'\n';
            return 0;
        }
        
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc) && !dis[nr][nc][ty^1]){
                if((ty==0 && a[nr][nc] < a[r][c]) || (ty==1 && a[nr][nc] > a[r][c])){
                    que.push({nr,nc,ty^1});
                    dis[nr][nc][ty^1] = dis[r][c][ty] + 1;
                }
            }
        }
    }

    cout<<-1<<'\n';
}