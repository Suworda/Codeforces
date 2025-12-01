#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
map<int,int> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    long long ans=0;

//直覺作法
    // int a,b;
    // for(int i=0; i<n; i++){
    //     cin>>a;
    //     cnt[a]++;
    // }

    // for(int i=0; i<m; i++){
    //     cin>>b;
    //     ans+=cnt[b];
    // }

    // cout<<ans<<'\n';
//

//本題希望的作法
    int a[n+1], b[m+1];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    a[n]=INF; b[m]=INF;
    
    int it_a=0, it_b=0;
    while(it_a < n || it_b < m){
        if(a[it_a] < b[it_b]) it_a++;
        else if(b[it_b] < a[it_a]) it_b++;
        else{
            int v = a[it_a];
            int x=0, y=0;
            while(a[it_a] == v) x++, it_a++;
            while(b[it_b] == v) y++, it_b++;
            ans += 1LL*x*y;
        }
        //cout<<it_a<<' '<<it_b<<" : "<<ans<<'\n';
    }
    cout<<ans<<'\n';
//

}