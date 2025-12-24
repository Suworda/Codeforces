#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int mi = 2e9;
        for(int i=0; i<n; i++){
            cin>>a[i];
            mi = min(mi,a[i]);
        }

        int ans1 = mi;
        int ans2 = 2e9;
        for(int i=0; i<n; i++){
            if(a[i] != mi) ans2 = min(ans2, a[i]-mi);
        }

        cout<<max(ans1, ans2)<<'\n';
    }

}