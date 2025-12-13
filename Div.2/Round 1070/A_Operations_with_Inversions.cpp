#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        bool found = false;
        do{
            found = false;
            for(int i=1; i<a.size(); i++){
                if(a[i-1] > a[i]){
                    ans++;
                    a.erase(a.begin() + i);
                    i--;
                    found = true;
                }
            }
        }while(found);
        cout<<ans<<'\n';
    }

}