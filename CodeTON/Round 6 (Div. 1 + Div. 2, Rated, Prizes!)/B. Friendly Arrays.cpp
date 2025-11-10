#include <iostream>
using namespace std;

void sol(){
    int n,m;
    cin>>n>>m;
    int a=0, x;
    for(int i=0; i<n; i++){
        cin>>x;
        a^=x;
    }

    int b=0;
    for(int i=0; i<m; i++){
        cin>>x;
        b|=x;
    }

    int mi, ma;
    if(n%2==0){
        mi=(a & (~b));
        ma=a;

    }else{
        mi=a;
        ma=(a | b);

    }


    cout<<mi<<' '<<ma<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();


}
