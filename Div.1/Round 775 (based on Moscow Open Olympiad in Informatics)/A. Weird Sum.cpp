#include <bits/stdc++.h>
using namespace std;
//#define int long long

int n,m;

//struct Point{
//    int x,y;
//    bool operator< (const Point &b) const{
//        return x+y < b.x+b.y;
//    }
//};


vector<int> pos_x[100005], pos_y[100005];

signed main(){
    cin>>n>>m;
    int c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>c;
            pos_x[c].push_back(i);
            pos_y[c].push_back(j);
        }
    }

    long long ans=0;
    for(int i=1; i<=100000; i++){
        //cout<<ans<<'\n';
        sort(pos_x[i].begin(), pos_x[i].end());
        sort(pos_y[i].begin(), pos_y[i].end());
        int sz=pos_x[i].size();
        for(int j=0; j<sz; j++){
            ans+=pos_x[i][j] * (-1*sz+1+2*j);
        }
        for(int j=0; j<sz; j++){
            ans+=pos_y[i][j] * (-1*sz+1+2*j);
        }
    }
    cout<<ans<<'\n';
}
