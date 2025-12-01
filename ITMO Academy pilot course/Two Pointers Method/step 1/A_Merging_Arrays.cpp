#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    vector<int> ans;
    cin>>n>>m;
    
// way1:
    // int a[n+1],b[m+1];
    // for(int i=0; i<n; i++) cin>>a[i];
    // for(int i=0; i<m; i++) cin>>b[i];
    // a[n] = INF; b[m] = INF;

    // int x=0, y=0;
    // while(x < n || y < m){
    //     if(a[x] < b[y]){
    //         ans.push_back(a[x++]);
    //     }else{
    //         ans.push_back(b[y++]);
    //     }
    // }
//

//way2:
    vector<int> a(n), b(m);
    for(int &x: a) cin>>x;
    for(int &x: b) cin>>x;

    auto it_b = b.begin();
    for(auto it_a = a.begin(); it_a < a.end(); it_a++){
        while(it_b < b.end() && *it_b < *it_a) ans.push_back(*it_b++);
        ans.push_back(*it_a);
    }

    while(it_b < b.end()) ans.push_back(*it_b++);
//

    for(int &v: ans) cout<<v<<' ';
}