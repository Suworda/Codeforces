#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m,greater<int>());

    long long ans=0;
    for(int i=0; i<min(n,m); i++){
        if(b[i]>a[i]) ans+=b[i]-a[i];
    }

    cout<<ans<<'\n';
}
