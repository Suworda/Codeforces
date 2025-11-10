#include <iostream>
using namespace std;

void sol(){
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++) cin>>x;

    if(n%2==0){
        cout<<2<<'\n';
        cout<<1<<' '<<n<<'\n';
        cout<<1<<' '<<n<<'\n';
    }else{
        cout<<4<<'\n';
        cout<<1<<' '<<n-1<<'\n';
        cout<<1<<' '<<n-1<<'\n';
        cout<<n-1<<' '<<n<<'\n';
        cout<<n-1<<' '<<n<<'\n';
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();


}
