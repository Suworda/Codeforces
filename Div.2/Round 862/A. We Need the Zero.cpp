#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int b[n+5];
    int cur=0;
    for(int x=0; x<(1<<8); x++){
        cur=(n%2==0 ? 0 : x);
        for(int j=0; j<n; j++){
            cur^=a[j];
        }

        if(cur==0){
            cout<<x<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
