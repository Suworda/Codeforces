#include <bits/stdc++.h>
using namespace std;
#define lid id*2
#define rid id*2+1

int n,m;
int seg[400005];

struct SegT{
    void pull(int id){
        seg[id] = min(seg[lid], seg[rid]);
    }
    
    void upd(int l, int r, int p, int x, int id){
        if(l == p && r == p){
            seg[id] = x;
            return;
        }
        int m = (l+r)/2;
        if(p <= m) upd(l,m,p,x,lid);
        else upd(m+1,r,p,x,rid);
        pull(id);
    }

    int query(int l, int r, int ql, int qr, int x, int id){
        if(qr < l || r < ql) return 0;

        if(l == r){
            if(seg[id] <= x){
                seg[id] = 2e9;
                return 1;
            }
            return 0;
        }
        
        int m = (l+r)/2;
        
        int L = 0, R = 0;
        if(seg[lid] <= x) L = query(l,m,ql,qr,x,lid);
        if(seg[rid] <= x) R = query(m+1,r,ql,qr,x,rid);
        pull(id);
        return L+R;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    SegT segt;
    for(int i=0; i<400005; i++) seg[i] = 2e9;
    cin>>n>>m;
    while(m--){
        int ty,i,h,l,r,p;
        cin>>ty;
        if(ty == 1){
            cin>>i>>h;
            segt.upd(0,n-1,i,h,1);
            
        }else{
            cin>>l>>r>>p;
            cout<<segt.query(0,n-1,l,r-1,p,1)<<'\n';
        }
    }
    // for(int j=1; j<3*n; j++) cout<<j<<':'<<seg[j]<<' ';
    // cout<<'\n';

}