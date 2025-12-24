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
        int a[n];
        int base = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(i > 0) base += abs(a[i] - a[i-1]);

        }

        int rst = 0;
        for(int i=0; i<n; i++){
            int d;
            if(i == 0){
                d = abs(a[i] - a[i+1]);

            }else if(i == n-1){
                d = abs(a[i] - a[i-1]);

            }else{
                d = abs(a[i] - a[i+1]) + abs(a[i] - a[i-1]) - abs(a[i-1] - a[i+1]);

            }

            rst = max(rst,d);
        }

        cout<<base-rst<<'\n';
        
    }

}