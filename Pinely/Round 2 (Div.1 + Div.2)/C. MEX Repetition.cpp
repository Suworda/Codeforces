#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    bool apr[n+5]={};
    k%=(n+1);

    int a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
        apr[a[i]]=true;
    }

    for(int i=0; i<=n; i++){
        if(!apr[i]){
            a[n]=i;
            break;
        }
    }

    rotate(a, a+n-k+1, a+n+1);

    for(int i=0; i<n; i++){
        cout<<a[i];
        cout<<(i==n-1 ? '\n' : ' ');
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--) sol();
}
