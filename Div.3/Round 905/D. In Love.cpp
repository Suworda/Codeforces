#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    multiset<int> L,R;

    int q;
    cin>>q;
    char c;
    int l,r;
    bool ans;
    while(q--){
        ans=false;
        cin>>c>>l>>r;
        if(c=='+'){
            L.insert(l);
            R.insert(r);
        }else{
            L.erase(L.find(l));
            R.erase(R.find(r));
        }

        if(L.size()==0){
            cout<<"No"<<'\n';
            continue;
        }

        //cout<< *(R.begin()) << ' ' << *(prev(L.end()));

        if(*(R.begin()) < *(prev(L.end())) ){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
}
