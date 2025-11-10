#include <iostream>
using namespace std;

void sol(){
    int cnt[35]={};
    int ans=0;
    int n,y;
    cin>>n>>y;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        for(int i=0; i<=30; i++){
            cnt[i]+=((x >> i) & 1);
        }
    }

    for(int i=0; i<=30; i++){
        //cout<<i<<' '<<cnt[i]<<'\n';
        if(cnt[i]*2 > n) ans += (1 << i);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
