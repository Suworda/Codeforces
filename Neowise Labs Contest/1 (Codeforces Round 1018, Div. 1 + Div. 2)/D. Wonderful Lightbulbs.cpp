#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int X=0, X_Y=0;
    int x,y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        X ^= x;
        X_Y ^= (x+y);
    }

    cout << X << ' ' << X_Y-X << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
}


