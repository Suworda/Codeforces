#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    double c;
    cin>>c;
    double l=0, r=1e6, ans;

    for(int i=0; i<100; i++){
        ans = (r+l)/2;
        if(ans*ans + sqrt(ans) > c){
            r=ans;
        }else if(ans*ans + sqrt(ans) < c){
            l=ans;
        }
    }
    
    cout<<fixed<<setprecision(15)<<ans<<'\n';


}