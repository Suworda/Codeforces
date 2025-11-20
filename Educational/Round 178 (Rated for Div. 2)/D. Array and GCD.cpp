#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
bitset<6000001> is_p;

void sol(){
    int n;
    cin>>n;
    long long coin=0;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n, greater<>());

    for(int i=0; i<n; i++){
        if(a[i] >= prime[i]) coin+=a[i]-prime[i];
        else{
            coin-=prime[i]-a[i];
            if(coin < 0){
                cout<<min(n-1,n-i)<<'\n';
                return;
            }
        }
    }
    cout<<0<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    is_p.set();
    for(int i=2; i<=6000000; i++){
        if(is_p[i]){
            prime.push_back(i);
            for(int j=i+i; j<=6000000; j+=i){
                is_p[j]=false;
            }
        }
    }

    //for(int i=0; i<1000; i++) cout<<prime[i]<<' ';

    int t;
    cin>>t;
    while(t--) sol();
}
//prime.size()<=400000


