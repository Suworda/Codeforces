#include <bits/stdc++.h>
using namespace std;

int cnt[1000005]={};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int cur=0;
    int ma = 0;
    pair<int,int> ans;
    for(int l=1, r=0; l<=n; l++){
        while(r < n && cur + (cnt[a[r+1]] == 0) <= k){
            if(cnt[a[r+1]] == 0) cur++;
            cnt[a[r+1]]++;
            r++;
            
            if(r - l +1 > ma){
                ma = r - l +1;
                ans = {l, r};
            }
            //cout<<l<<' '<<r<<' '<<cur<<'\n';
        }
        if(cnt[a[l]] == 1) cur--;
        cnt[a[l]]--;
    }

    cout << ans.first << ' ' << ans.second << '\n';

}