#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

void sol(){
    int n,s1,s2;
    cin>>n>>s1>>s2;
    bool flag=false;
    if(s1>s2){
        swap(s1,s2);
        flag=true;
    }

    vector<pair<int,int>> r;
    vector<int> a,b;
    int cnt;
    for(int i=1; i<=n; i++){
        cin>>cnt;
        r.push_back({cnt,i});
    }

    sort(r.begin(), r.end(),greater<pair<int,int>>());

    int L[n]={},R[n]={};
    L[0]=r[0].x*s1; R[n-1]=r[n-1].x*s2;

    for(int i=1; i<=n; i++){
        L[i]=L[i-1]+r[i].x*s1;
    }

    for(int i=n-2; i>=0; i--){
        R[i]=R[i+1]+r[i].x*s2;
    }

    for(int i=0; i<n; i++){
        //cout<<L[i]<<' '<<R[i]<<'\n';
        if(L[i]<R[i]){
            a.push_back(r[i].y);
        }else{
            b.push_back(r[i].y);
        }
    }

    if(flag) swap(a,b);

    cout<<a.size();
    for(int i=0; i<a.size(); i++) cout<<' '<<a[i];
    cout<<'\n';

    cout<<b.size();
    for(int i=0; i<b.size(); i++) cout<<' '<<b[i];
    cout<<'\n';

}

signed main(){
    int t;
    cin>>t;
    while(t--) sol();
}

/*
3
7 1 3
8 6 4 4 4 1 7
*/
