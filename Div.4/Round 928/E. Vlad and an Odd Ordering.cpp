#include <bits/stdc++.h>
using namespace std;

int f(int n ,int k){
    int x = (n+1)/2;
    if(k <= x) return 2*k-1;

    return f(n-x , k-x) * 2;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<f(n,k)<<'\n';
    }
}
