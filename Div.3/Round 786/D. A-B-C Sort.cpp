#include <iostream>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=(n%2); i<n-1; i+=2){
        if(a[i]>a[i+1]) swap(a[i],a[i+1]);
    }

    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();

}
