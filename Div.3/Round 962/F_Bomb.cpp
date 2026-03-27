#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005], b[200005];

bool valid(int v){
    int rst = 0;
    for(int i=0; i<n; i++){
        if(a[i] >= v){
            if(a[i] <= b[i]) rst++;
            else rst += (a[i] - v)/b[i] + 1;
            
        }
    }   

    return rst <= k;
}

void sol(){
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    int l=0, r=2e9, v=-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(valid(m)){
            v = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] >= v){
            if(a[i] <= b[i]){
                ans += a[i];
                a[i] = 0;
                k--;

            }else{
                int x = (a[i] - v)/b[i] + 1;
                ans += x*(2*a[i] + (x-1)*(-b[i]))/2;
                a[i] -= x*b[i];
                a[i] = max(0ll, a[i]);
                k -= x;
            }
        }
    }
    
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        if(a[i]) pq.push(a[i]);
    }

    while(k-- && pq.size()){
        ans += pq.top();
        pq.pop();
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