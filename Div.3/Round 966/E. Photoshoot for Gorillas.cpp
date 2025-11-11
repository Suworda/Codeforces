#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sol(){
    int n,m,k;
    cin>>n>>m>>k;
    int w;
    cin>>w;
    int a[w];
    for(int i=0; i<w; i++){
        cin>>a[i];
    }

    vector<int> v;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            v.push_back(min(min(i,n+1-i),min(k,n-k+1)) * min(min(j,m-j+1),min(k,m-k+1)));
            //cout<<v.back()<<'\n';;
        }
    }

    sort(v.begin(), v.end(), greater<>());
    sort(a, a+w, greater<>());

    long long ans=0;
    for(int i=0; i<w; i++){
        ans+=1LL*v[i]*a[i];
        //cout<<v[i]*a[i]<<'\n';
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
