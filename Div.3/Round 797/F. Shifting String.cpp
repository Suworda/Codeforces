#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    string s,t1,t2;
    cin>>n>>s;
    t1=s; t2=s;
    int p[205];
    for(int i=0; i<n; i++){
        cin>>p[i];
        p[i]--;
    }

    long long ans=1;
    bool vis[205]={};
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        int now = i;
        string res = string(1, s[now]);
        while(p[now] != i){
            now = p[now];
            vis[now] = true;
            res += s[now];
        }
        for(long long t=1; ; t++){
            if(res == res.substr(t) + res.substr(0,t)){
                ans = lcm(ans, t);
                break;
            }
        }
    }

    cout<<ans<<'\n';






//    string x[n];
//    for(int i=0; i<n; i++){
//        x[i]+=s[i];
//    }
//
//    vector<int> cnt(n,-1);
//
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            x[j]+=x[p[j]][i];
//        }
//        for(int j=0; j<n; j++){
//            cout<<x[j][i+1];
//        }
//        cout<<'\n';
//    }
//
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n/2; j++){
//            if(x[i].substr(0,j+1) == x[i].substr(j+1,j+1)){
//                cnt[i]=j+1;
//            }
//        }
//        if(cnt[i]==-1) cnt=n;
//    }






//    long long cnt=0;
//    while(cnt==0 || t1!=s){
//        for(int i=0; i<n; i++){
//            t2[i]=t1[p[i]];
//        }
//        cout<<t2<<'\n';
//        swap(t1,t2);
//        cnt++;
//    }

    //cout<<cnt<<'\n'<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
