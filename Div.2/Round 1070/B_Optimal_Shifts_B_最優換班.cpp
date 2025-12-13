#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int ans=0;
        int prev;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '1'){
                prev = i;
                break;
            }
        }

        for(int i=0; i<n; i++){
            if(s[i]-'0' == 1){
                prev = i;
            }else{
                if(prev > i) ans = max(ans, i+n - prev);
                else ans = max(ans, i - prev);
            }
        }
        
        cout<<ans<<'\n';
    }

}