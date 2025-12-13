#include <bits/stdc++.h>
using namespace std;

map<string,int> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin>>n>>s;
    if(s.size() > n){
        cout<<-1<<'\n';
        return 0;
    }

    int ans = 100;
    queue<string> que;
    que.push(s);
    cnt[s]=0;

    while(!que.empty()){
        string cur = que.front();
        //cout<<cur<<'\n';
        que.pop();

        if(cur.size() == n){
            ans = min(ans, cnt[cur]);
        }
        
        if(cur.size() == 19) continue;
        for(int i=0; i<cur.size(); i++){
            string next = to_string(stoll(cur) * (cur[i]-'0'));
            if(cnt.find(next) == cnt.end()){
                que.push(next);
                cnt[next] = cnt[cur]+1;
            }

        }

    }

    if(ans == 100) cout<<-1<<'\n';
    else cout<<ans<<'\n';



}