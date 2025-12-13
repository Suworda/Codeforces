#include <bits/stdc++.h>
using namespace std;

void sol(){
    int q;
    cin>>q;
    deque<int> dq;
    long long base = 0;
    long long n=0;
    long long cur=0;

    bool reversed = false;
    
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            if(!reversed){
                cur += base - n*dq.back();
                dq.push_front(dq.back());
                dq.pop_back();
            }else{
                cur += base - n*dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
            }

        }else if(ty == 2){
            cur = base*(n+1) - cur;
            reversed = !reversed;
            
        }else{
            int x;
            cin>>x;
            base+=x;
            n++;
            cur += x*n;
            if(!reversed) dq.push_back(x);
            else dq.push_front(x);
        }

        cout<<cur<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}