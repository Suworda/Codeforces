#include <iostream>
using namespace std;

void sol(){
    int n;
    string s;
    cin>>n>>s;
    long long sum[n+1]={};
    bool apr[128]={};

    for(int i=1; i<=n; i++){
        sum[i]=sum[i-1]+(!apr[s[i-1]]);
        apr[s[i-1]]=true;
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=sum[i];
    }

    cout<<ans<<'\n';



}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) sol();
}
