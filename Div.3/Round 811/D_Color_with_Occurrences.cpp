#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    vector<pair<int,int>> ans;
    bitset<101> red;

    string t;
    cin>>t;
    int t_sz = t.size();
    t = ' ' + t;
    for(int i=0; i<15; i++) t += ' ';

    int n;
    cin>>n;
    string s[n+1];
    for(int i=1; i<=n; i++) cin>>s[i];

    int l = 0, r = 0, ty = 0;
    for(int i=1; i<=t_sz; i++){
        for(int j=1; j<=n; j++){
            if(s[j] == t.substr(i, s[j].size()) && i + s[j].size() -1 > r){
                l = i;
                r = i + s[j].size() -1;
                ty = j;
            }
        }
        if(!red[i]){
            ans.push_back({ty,l});
            for(int j=l; j<=r; j++) red[j] = 1;
        }
    }

    bool ok = true;
    for(int i=1; i<=t_sz; i++) if(!red[i]) ok = false;

    if(ok){
        cout<<ans.size()<<'\n';
        for(auto [a,b]: ans) cout<<a<<' '<<b<<'\n';

    }else cout<<-1<<'\n';


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--) sol();

}















// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define ll long long

// void sol(){
//     vector<pair<int,int>> ans;
//     bitset<101> red;

//     string t;
//     cin>>t;
//     int t_sz = t.size();
//     t = ' ' + t;
//     for(int i=0; i<15; i++) t+=' ';

//     int n;
//     cin>>n;
//     string s[n+1]={};
//     for(int i=1; i<=n; i++) cin>>s[i];

//     int l = 0;
//     int last_p = 0;
//     int last_ty = -1;
    
//     for(int i=1; i<=t_sz; i++){
//         for(int j=1; j<=n; j++){
//             if(s[j] == t.substr(i,s[j].size())){
//                 if(i + s[j].size()-1 > last_p){
//                     last_p = i + s[j].size()-1;
//                     last_ty = j;
//                     l = i;
//                 }
//             }
//         }

//         if(!red[i]){
//             if(l > last_p){
//                 cout<<-1<<'\n';
//                 return;
//             }
            
//             ans.push_back({last_ty, l});
//             for(int j=l; j<=last_p; j++) red[j]=1;
//         }

//     }

//     bool all_red = 1;
//     for(int i=1; i<=t_sz; i++){
//         if(!red[i]) all_red = 0;
//     }

//     if(all_red){
//         cout<<ans.size()<<'\n';
//         for(auto [a,b]: ans) cout<<a<<' '<<b<<'\n';

//     }else cout<<-1<<'\n';
// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int q;
//     cin>>q;
//     while(q--) sol();

// }