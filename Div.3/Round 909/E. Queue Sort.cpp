#include <iostream>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int a[n];
    int mi=2e9;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mi=min(mi,a[i]);
    }

    int p=0;
    for(int i=0; i<n; i++){
        if(a[i]==mi){
            p=i;
            break;
        }
    }

    bool ok=true;
    for(int i=p+1; i<n; i++){
        if(a[i-1]>a[i]){
            ok=false;
            break;
        }
    }

    if(!ok) cout<<-1<<'\n';
    else cout<<p<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();

}
