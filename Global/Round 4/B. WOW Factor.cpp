#include <bits/stdc++.h>
using namespace std;

#define int long long

int w_sum[1000005]={};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    vector<pair<int,int>> cnt;
    int n=s.size();
    int cur=0;
    int cnt_o=0;
    long long ans=0;

    //O(N^2)
//    for(int i=0; i<n; i++){
//        cur+=(s[i]=='v');
//        cnt_o+=(s[i]=='o');
//        if(s[i]=='o' || i==n-1){
//            if(cur-1 > 0){
//                if(i==n-1) cnt_o++;
//                cnt.push_back({cur-1,cnt_o});
//            }
//            cur=0;
//        }
//    }
//
//    for(int i=0; i<cnt.size(); i++){
//        for(int j=i+1; j<cnt.size(); j++){
//            ans+= cnt[j].first * cnt[i].first * (cnt[j].second - cnt[i].second);
//        }
//    }

    //O(N)
    for(int i=0; i<n; i++){
        cur+=(s[i]=='v');
        if(s[i]=='o') cur=0;

        if(i>0) w_sum[i]=w_sum[i-1];
        if(cur >= 2){
            w_sum[i]++;
        }

    }

    for(int i=0; i<n; i++){
        if(s[i]=='o'){
            ans+=(w_sum[i] * (w_sum[n-1] - w_sum[i]));
        }
    }

    cout<<ans<<'\n';







}
