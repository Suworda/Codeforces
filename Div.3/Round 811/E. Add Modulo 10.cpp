#include <iostream>
using namespace std;

void sol(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        while(a[i]%10 != 2 && a[i]%10 != 0) a[i]+=a[i]%10;
    }

    bool ans=true;
    for(int i=1; i<n; i++){
        if( (a[i] != a[i-1]) && (a[i]%10 == 0 && a[i-1]%10 == 0) ) ans=false;
    }

    if(!ans){
        cout<<"NO\n";
        return;
    }

    ans=true;
    for(int i=1; i<n; i++){
        if(a[i]%20 != a[i-1]%20) ans=false;
    }

    if(ans) cout<<"YES\n";
    else cout<<"NO\n";


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();

}
