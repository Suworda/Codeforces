#include <bits/stdc++.h>
using namespace std;

char c;
char stk[100005];
int top = -1;

char get_need(char c){
    if(c == ')') return '(';
    if(c == ']') return '[';
    if(c == '}') return '{';
    if(c == '>') return '<';
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;

    while(cin>>c){
        char need = get_need(c);

        if(need){
            if(top == -1){
                cout<<"Impossible\n";
                return 0;
            }

            if(need != stk[top]) ans++;
            top--;

        }else{
            stk[++top] = c;
        }
    }

    if(top == -1) cout<<ans<<'\n';
    else cout<<"Impossible\n";

}