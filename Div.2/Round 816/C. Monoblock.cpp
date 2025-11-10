#include <iostream>
using namespace std;

#define int long long

long long cur=0;
int n,q;
int a[100005];

void query(){
    int p,x;
    cin>>p>>x;

    if(a[p] == a[p-1] && x!=a[p-1]) cur+=(p-1)*(n-p+1);
    if(a[p] != a[p-1] && x==a[p-1]) cur-=(p-1)*(n-p+1);
    if(a[p] == a[p+1] && x!=a[p+1]) cur+=(p)*(n-p);
    if(a[p] != a[p+1] && x==a[p+1]) cur-=(p)*(n-p);

//    cur+=(n-p+1)*(p-1)*d;
    cout<<cur<<'\n';

    a[p]=x;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>q;
    a[0]=-1; a[n+1]=-1;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int d=0;
    for(int i=1; i<=n; i++){
        if(a[i]!=a[i-1]){
            d+=i;
        }else{
            d++;
        }
        cur+=d;
    }

    while(q--) query();
}
