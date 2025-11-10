#include <iostream>
using namespace std;

void sol(){
    int n,m,k;
    cin>>n>>m>>k;
    if(k>3){
        cout<<0<<'\n';
    }

    if(k==3){
        cout<<m-(min(n,m) + max(m/n-1 , 0))<<'\n';
    }

    if(k==2){
        cout<<(min(n,m) + max(m/n-1 , 0))<<'\n';
    }

    if(k==1){
        cout<<1<<'\n';
    }
//    int ans=0;
//    for(int i=0; i<=m; i++){
//        int cur=i;
//        int kind=1;
//        for(int j=n; j>=1; j--){
//            if(cur%j!=cur) kind++;
//            cur%=j;
//        }
//        ans+=(kind==k);
//        //cout<<kind<<' ';
//    }
//    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
