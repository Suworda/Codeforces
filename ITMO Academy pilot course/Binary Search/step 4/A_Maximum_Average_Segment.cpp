#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,d;
int l, r;
int a[100005];

bool valid(double v){
    double b[n+1]={};
    double sum[n+1]={};
    for(int i=1; i<=n; i++){
        b[i] = a[i] - v;
        sum[i] = sum[i-1] + b[i];
    }

    double mi=2e9;
    int p=-1;
    for(int i=d; i<=n; i++){
        double cur = sum[i];
        if(sum[i-d] < mi){
            mi = sum[i-d];
            p = i-d+1;
        }
        if(cur - mi >= 0){
            l = p;
            r = i;
            return true;
        }
    }

    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>d;
    for(int i=1; i<=n; i++) cin>>a[i];

    double low=0, hi=2e9;
    for(int i=0; i<1200; i++){
        double m = (low+hi)/2;
        if(valid(m)){
            low = m;
        }else{
            hi = m;
        }
    }

    cout<<l<<' '<<r<<'\n';
}