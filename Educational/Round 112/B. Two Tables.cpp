#include <iostream>
using namespace std;

void sol(){
    int W,H;
    int x1,x2,y1,y2;
    int w,h;
    cin>>W>>H;
    cin>>x1>>y1>>x2>>y2;
    cin>>w>>h;

    int ans=2e9;
    int X=abs(x1-x2), Y=abs(y1-y2);
    if(w+X <= W){
        ans=min(ans, max(0, x2-(W-w)));
        ans=min(ans, max(0, w-x1));
    }
    if(h+Y <= H){
        ans=min(ans, max(0, y2-(H-h)));
        ans=min(ans, max(0, h-y1));
    }

    if(ans==2e9) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();

}
