#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
char g[505][505];

bool valid(int r, int c){
    return r>=1 && r<=n && c>=1 && c<=m && g[r][c]=='X';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    int need=0;   
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>g[i][j];
            if(g[i][j] == '.'){
                g[i][j] = 'X';
                need++;
            }
        }
    }
    need -= k;

    queue<pair<int,int>> q;
    if(need){
        for(int i=1; i<=n && q.empty() ; i++){
            for(int j=1; j<=m; j++){
                if(g[i][j] == 'X'){
                    q.push({i,j});
                    g[i][j] = '.';
                    need--;
                    break;
                }
            }
        }
    }

    while(q.size() && need){
        auto [r,c] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc)){
                g[nr][nc]='.';
                need--;
                q.push({nr,nc});
            }
            if(need == 0) break;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<g[i][j];
        }
        cout<<'\n';
    }
    
}