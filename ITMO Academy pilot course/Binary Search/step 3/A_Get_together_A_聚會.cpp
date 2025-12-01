#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int v[100005];

bool valid(double t){
    double l=-2e9,r=2e9;
    for(int i=0; i<n; i++){
        l = max(l, a[i]-v[i]*t);
        r = min(r, a[i]+v[i]*t);
    }

    // for(int i=0; i<n; i++){
    //     if(a[i] - v[i]*t > l || a[i] + v[i]*t < r){
    //         return false;
    //     }
    // }

    return l<r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>v[i];
    }

    double ans;
    double l=0, r=2e9;
    for(int i=0; i<100; i++){
        ans = (l+r)/2;

        if(valid(ans)){
            r=ans;
        }else{
            l=ans;
        }
    }

    cout<<fixed<<setprecision(15)<<ans<<'\n';
}