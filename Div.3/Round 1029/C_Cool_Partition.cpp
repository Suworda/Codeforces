#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int n;
    cin>>n;
    bool apr[n+5]={};
    int cur[n+5]={};
    int need=0, ans=0, sum=0;
    vector<int> v;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(apr[x] && cur[x] != ans+1){
            need--;
            cur[x] = ans+1;
        }
        else v.push_back(x);

        if(need == 0){
            ans++;
            for(int num: v){
                if(!apr[num]){
                    sum++;
                    apr[num] = 1;
                }
            }
            v.clear();
            need = sum;
        }
    }    
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}