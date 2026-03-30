#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int ans = -1;
    int l=2, r=999;
    while(l < r){
        int ml = (2*l+r)/3;
        int mr = (l+2*r)/3;
        cout<<"? "<<ml<<' '<<mr<<'\n';
        cout.flush();

        int rst;
        cin>>rst;
        
        if(rst == ml * mr){
            l = mr+1;

        }else if(rst == ml * (mr+1)){
            l = ml+1;
            r = mr;
            
        }else{
            r = ml;
            
        }
        
    }

    cout<<"! "<<l<<'\n';
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}