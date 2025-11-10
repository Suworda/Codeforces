#include <iostream>
using namespace std;

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pxor[n+1];
        pxor[0]=0;
        int a[n+1];
        int cur=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            cur^=a[i];
            pxor[i]=pxor[i-1]^a[i];
        }
        if(cur==0){
            cout<<"YES\n";
            continue;
        }

        bool ans=false;
        for(int i=1; i<=n; i++){
            if(pxor[i-1] == (pxor[n]^pxor[i]) && (a[i]==0 || a[i]==pxor[i-1])){
                ans=true;
                break;
            }
        }

        cout<<(ans ? "YES" : "NO")<<'\n';

    }


}
