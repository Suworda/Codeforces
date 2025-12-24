#include <bits/stdc++.h>
using namespace std;

int n;
int N;

bool cmp(int x, int y){
    int a=0,b=0;
    while(x & 1){
        a ++;
        x >>= 1;
    }
    while(y & 1){
        b++;
        y >>= 1;
    }

    if(a != b) return a > b;
    return x < y;
}

void sol(){
    cin>>n;
    N = 1 << n;
    vector<int> a(N);
    iota(a.begin(), a.end(),0);

    sort(a.begin(), a.end(), cmp);

    for(int i=0; i<N; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}