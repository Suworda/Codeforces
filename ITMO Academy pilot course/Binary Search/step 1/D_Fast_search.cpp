#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    a[n]=2e9;
    int q;
    cin>>q;
    int l,r,x,y;
    int ans1, ans2;
    while(q--){
        ans1=-1;
        ans2=-1;
        cin>>x>>y;
        l=0; r=n;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid] >= x){
                ans1 = mid;
                r = mid -1;
            }else{
                l = mid +1;
            }
        }

        l=0; r=n;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid] > y){
                ans2 = mid;
                r = mid -1;
            }else{
                l = mid +1;
            }
        }

        cout << (ans2 - ans1) << ' ';
    }

}