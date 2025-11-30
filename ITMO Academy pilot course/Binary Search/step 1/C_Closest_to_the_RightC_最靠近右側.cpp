#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int l,r;
    while(k--){
        int x;
        cin>>x;
        int mid,ans=n;

        l=0; r=n-1;
        while(l<=r){
            mid=(l+r)/2;
            
            if(a[mid] >= x){
                ans=mid;
                r=mid-1;

            }else{
                l=mid+1;

            }

        }
        
        cout<<ans+1<<'\n';
    }

}