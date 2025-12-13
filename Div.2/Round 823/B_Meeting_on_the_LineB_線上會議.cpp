#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
int x[MAXN], t[MAXN];

double f(double mid){
    double rst=0;
    for(int i=0; i<n; i++){
        rst = max(rst, t[i] + abs(x[i] - mid));
    }
    return rst;
}

void sol(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n; i++){
        cin>>t[i];
    }

    double ans = 9e18;
    double l=0, r=1e10;
    for(int round=0; round<100; round++){
        ans = (l+r)/2;

        double ml = (2*l+r)/3;
        double mr = (l+2*r)/3;

        if(f(ml) > f(mr)){
            l = ml;
        }else{
            r = mr;
        }
    }
    cout << fixed << setprecision(15)<< ans <<'\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    while(T--) sol();

}