#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    string s;
    cin>>n>>s;
    s='0'+s;
    vector<int> rst(n+1);
    iota(rst.begin(), rst.end(), 0);
    long long ans=0;
    for(int i=1; i<=n; i++){
        if(s[i]=='0'){
            ans+=rst[i];
            for(int j=i; j<=n && s[j]=='0'; j+=i){
                rst[j]=min(rst[j],i);
            }
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


