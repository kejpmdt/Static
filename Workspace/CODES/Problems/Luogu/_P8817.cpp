#include<bits/stdc++.h>
using namespace std;
vector<int>tos[2505],cans[2505];
vector<pair<int,int>>uu;
int dis[2505][2505],vVv[2505],n,k,m;
void bfs(int st){
    queue<int>q;
    q.push(st);
    int nw;
    while(!q.empty()){
        nw=q.front();
        q.pop();
        if(dis[st][nw]!=k+1)for(auto i:tos[nw])if(!dis[st][i])q.push(i),dis[st][i]=dis[st][nw]+1;
    }
}
void md(void){
    for(int i=1;i<=n;++i)bfs(i),dis[i][i]=0;
    for(int i=1;i<=n;++i){tos[i].clear();for(int j=1;j<=n;++j)if(dis[i][j])tos[i].push_back(j);}
    for(int i=2;i<=n;++i){
        uu.clear();for(int j:tos[i])if(j!=i)if(dis[j][1])uu.push_back({vVv[j],j});
        sort(uu.begin(),uu.end(),greater<pair<int,int>>());
        for(int j=0;j<5&&j<(int)uu.size();++j)cans[i].push_back(uu[j].second);
    }
}
long long ans=0;
bool pd[2505];
signed main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;++i)scanf("%d",&vVv[i]);
    int u,v;
    while(m--){
        scanf("%d%d",&u,&v);
        tos[u].push_back(v);
        tos[v].push_back(u);
    }
    md();
    for(int b=1;b<=n;++b)for(auto c:tos[b])for(auto d:cans[c])if(d!=b)for(auto a:cans[b])if(a!=c&&a!=d)ans=max(ans,(long long)vVv[a]+vVv[b]+vVv[c]+vVv[d]);
    cout<<ans;
    return 0;
}