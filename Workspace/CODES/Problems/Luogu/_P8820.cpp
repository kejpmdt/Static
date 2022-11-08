#include<bits/stdc++.h>
using namespace std;
int n,k,q;
struct ZT{
    long long times[3][3];
    long long* operator[](int x){
        return times[x];
    }
    ZT(int a=0,int b=0){
        times[0][0]=times[0][1]=times[0][2]=0;
        times[1][0]=times[1][1]=times[1][2]=0;
        times[2][0]=times[2][1]=times[2][2]=0;
        for(int i=0;i<k;++i)times[0][i]+=a,times[i][0]+=b;
    }
    friend ZT operator +(ZT a,ZT b){
        ZT u;
        int i,j,x;
        for(i=0;i<k;++i){
            for(j=0;j<k;++j){
                u[i][j]=0x7fffffff;
                for(x=0;x<k;++x){
                    u[i][j]=min(u[i][j],a[i][x]+b[(k-x)%k][j]);
                }
            }
        }
        return u;
    }
    friend void operator +=(ZT&a,ZT b){a=a+b;}
};
ZT st[30][200005];
int fa[30][200005];
int depth[200005];
int v[200005];
vector<int>tos[200005];
void dfs(int nw,int f){
    static int x=0;
    depth[nw]=++x;
    fa[0][nw]=f;
    for(auto i:tos[nw])if(!depth[i])dfs(i,nw);
    --x;
}
void build(void){
    for(int i=1;i<=n;++i)st[0][i]=ZT(v[i],v[fa[0][i]]);
    for(int i=1;i<=25;++i)
        for(int j=1;j<=n;++j){
            fa[i][j]=fa[i-1][fa[i-1][j]];
            st[i][j]=st[i-1][j]+st[i-1][fa[i-1][j]];
        }
}
void init(void){
    scanf("%d%d%d",&n,&q,&k);
    int a,b;
    for(int i=1;i<=n;++i)scanf("%d",&v[i]);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        tos[a].push_back(b);
        tos[b].push_back(a);
    }
    dfs(1,1);
    build();
}
long long ask(int a,int b){
    ZT ans1,ans2;
    if(depth[a]<depth[b])swap(a,b);
    int i;
    i=0;
    while(depth[fa[i][a]]>depth[b])++i;
    while(~i){
        if(depth[fa[i][a]]>depth[b])ans1+=st[i][a],a=fa[i][a];
        --i;
    }
    if(depth[a]!=depth[b])a=fa[0][a];
    i=0;
    while(fa[i][a]!=fa[i][b])++i;
    while(~i){
        if(fa[i][a]!=fa[i][b]){
            ans1+=st[i][a];
            ans2+=st[i][b];
            a=fa[i][a];
            b=fa[i][b];
        }
        --i;
    }
    ans1+=ans2;
    return ans1[0][0];
}
int main(){
    init();
    int a,b;
    while(q--){
        scanf("%d%d",&a,&b);
        cout<<ask(a,b)<<'\12';
    }
    return 0;
}
