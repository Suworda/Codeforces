#include <bits/stdc++.h>>
using namespace std;

#define int long long

struct People{
    int cost,cnt;
    operator< (const People &b) const{
        return cost<b.cost;
    }
};

void sol(){
    int n,p;
    cin>>n>>p;
    vector<People> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].cnt;
    }
    for(int i=0; i<n; i++){
        cin>>a[i].cost;
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++){
        //cout<<a[i].cost<<' '<<a[i].cnt<<'\n';
    }

    int cur=0;
    long long ans=p;
    int i=0;
    while(cur<n-1){
        ans+=min(p,a[i].cost)*min(n-cur-1,a[i].cnt);
        cur+=a[i].cnt;
        i++;
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

/*
3
7 1 3
8 6 4 4 4 1 7
*/
