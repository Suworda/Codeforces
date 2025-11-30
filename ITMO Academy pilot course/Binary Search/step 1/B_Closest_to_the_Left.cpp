#include <bits/stdc++.h>
using namespace std;

int a[100005]={};

bool valid(int mid, int x){
    return a[mid] <= x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    while(k--){
        int x;
        cin>>x;

        int l=1, r=n;
        int mid, ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(valid(mid,x)){
                ans = mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        cout<<ans<<'\n';
    }
}