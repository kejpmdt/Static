#include<bits/stdc++.h>
using namespace std;
long long f[100005][2];
vector<int>tos[100005];
int v[100005];
long long dfs(int nw,int x){
    if(f[nw][x]){
        return f[nw][x];
    }
    long long re;
    if(x==1){
        re=v[nw];
    }
    else{
        re=0x7fffffff;
    }
    for(auto i:tos[nw]){
        if(x){
            re=max(re,v[nw]+dfs(i,x^1));
        }
        else{
            re=min(re,v[nw]+dfs(i,x^1));
        }
    }
    f[nw][x]=re;
    return re;
}
int main(){
    freopen("T2.in","r",stdin);
    freopen("T2.out","w",stdout);
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&x,&y);
        tos[x].push_back(y);
    }
    for(int i=1;i<=n;++i){
        cout<<dfs(i,1)<<'\12';
    }
    return 0;
}
