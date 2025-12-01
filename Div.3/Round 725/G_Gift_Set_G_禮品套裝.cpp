#include <bits/stdc++.h>
using namespace std;

long long x,y,a,b;

bool valid(long long t){
    //cout << 1.0*(x-y - t*(b-a))/(2*(a-b));
    //return 1.0*(x-y - t*(b-a))/(2*(a-b)) >= 0;

    int d = abs(a-b);
    if(d == 0) return min(x/a , y/b) >= t;

    long long base = min(a,b);
    if(x - base*t < 0 || y - base*t < 0) return false;

    int X = x - base*t;
    int Y = y - base*t;
    return (X/d + Y/d) >= t;

    
}

void sol(){
    cin>>x>>y>>a>>b;
    int ans=0;
    int l=1, r=1e9;
    while(l<=r){
        int mid = (l+r)/2;
        //cout<<mid<<'\n';

        if(valid(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    cout<<ans<<'\n';
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}