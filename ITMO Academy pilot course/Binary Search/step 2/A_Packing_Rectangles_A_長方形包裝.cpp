#include <bits/stdc++.h>
using namespace std;

int w,h,n;

bool valid(long long x){
    if(x<h || x<w) return false;
    return (x/w) > (n-1)/(x/h);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>w>>h>>n;
    long long ans=0;
    long long l=1, r=9e18;
    while(l<=r){
        long long mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<'\n';

}