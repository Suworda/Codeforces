#include <bits/stdc++.h>>
using namespace std;

#define int long long

void sol(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());

    m-=n;
    m-=a[0];
    for(int i=0; i<n-1; i++){
        m-=a[i];
    }

    cout<<( m>=0 ? "YES\n" : "NO\n");
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
