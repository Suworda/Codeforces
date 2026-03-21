#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int n;
    cin>>n;

    int ans=0;
    int x=2e9, y=2e9;
    for(int i=0; i<n; i++){
        int v;
        cin>>v;
        if(x > y) swap(x,y);

        if(v <= x){
            x = v;

        }else if(v <= y){
            y = v;

        }else{
            x = v;
            ans++;
        }
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}