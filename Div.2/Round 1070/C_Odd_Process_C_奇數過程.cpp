#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool all_odd = true;
        bool all_even = true;

        vector<int> odd, even;
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x%2 == 0){
                all_odd = false;
                even.push_back(x);
            }else{
                all_even = false;
                odd.push_back(x);
            }
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end(), greater<>());

        if(all_even){
            for(int i=1; i<=n; i++){
                cout<<0<<' ';
            }
            cout<<'\n';
            continue;
        }

        if(all_odd){
            for(int i=1; i<=n; i++){
                if(i%2 == 1) cout<<odd[0]<<' ';
                else cout<<0<<' ';
            }
            cout<<'\n';
            continue;
        }

        long long cur = odd[0];
        cout<<cur<<' ';
        // continue;

        int r = odd.size()-1;
        int it = 0;
        for(int i=1; i<n; i++){
            if(it < even.size()) cur += even[it++];
            else{
                r-=2;
                if(r < 0) cur = 0;
                else cur -= even.back();
                it--;
            }
            cout<<cur<<' ';
        }
        cout<<'\n';
    }

}