#include <iostream>
using namespace std;

#define int long long

void sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    long long ans=0;
    int d=0;

    for(int i=0; i<n-1; i++){
        a[i+1]+=d;
        if(a[i+1]-a[i]<=0){
            ans+=abs(a[i+1]-a[i]);
            a[i]=a[i+1];
        }else{
            ans+=abs(a[i+1]-a[i]);
            d-=abs(a[i+1]-a[i]);
            a[i+1]=a[i];

        }
    }

//    for(int i=0; i<n; i++){
//        cout<<a[i]<<'\n';
//    }
    cout<<ans+abs(a[n-1])<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
