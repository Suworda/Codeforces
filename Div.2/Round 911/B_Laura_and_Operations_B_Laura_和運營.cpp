#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

vector<int> ans;
int dp[205][205][205];
int vis[205][205][205];

int f(int a, int b, int c){
    if(a<0 || b<0 || c<0) return 0;
    if(vis[a][b][c]) return dp[a][b][c];
    vis[a][b][c] = 1;

    if(b == 0 && c == 0 && a) return 4;
    if(a == 0 && c == 0 && b) return 2;
    if(a == 0 && b == 0 && c) return 1;
    
    int rst = 0;
    rst |= f(a-1, b-1, c+1) | f(a-1, b+1, c-1) | f(a+1, b-1, c-1);

    return dp[a][b][c] = rst;
}

void sol(){
    int a,b,c;
    cin>>a>>b>>c;
    int rst = f(a,b,c);
    for(int i=2; i>=0; i--) cout<<((rst>>i)&1)<<' ';
    cout<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    while(T--) sol();

}