#include<bits/stdc++.h>
using namespace std;
double x[100005];
double y[100005];
double e[100005];
double yni[100005];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    double xb,yb;
    xb=yb=0;
    for(int i=1;i<=n;++i){
        xb+=x[i];
        yb+=y[i];
    }
    xb/=n;
    yb/=n;
    double an,bn;
    bn=0;
    an=0;
    for(int i=1;i<=n;++i){
        bn+=(x[i]-xb)*(y[i]-yb);
        an+=(x[i]-xb)*(x[i]-xb);
    }
    bn/=an;
    an=yb-bn*xb;
    for(int i=1;i<=n;++i){
        yni[i]=bn*x[i]+an;
    }
    for(int i=1;i<=n;++i){
        e[i]=y[i]-yni[i];
    }
    double r;
    r=0;
    for(int i=1;i<=n;++i){
        r+=(x[i]-xb)*(y[i]-yb);
    }
    double u1,u2;
    u1=u2=0;
    for(int i=1;i<=n;++i){
        u1+=(x[i]-xb)*(x[i]-xb);
        u2+=(y[i]-yb)*(y[i]-yb);
    }
    u1=u1*u2;
    u2=sqrt(u1);
    r/=u2;
    double R2;
    R2=0;
    u1=0;
    for(int i=1;i<=n;++i){
        R2+=(y[i]-yni[i])*(y[i]-yni[i]);
        u1+=(y[i]-yb)*(y[i]-yb);
    }
    R2/=u1;
    R2=1-R2;
    printf("yni =%15lfx+%15lf\n",bn,an);
    printf("yni:");
    for(int i=1;i<=n;++i)printf("%15lf ",yni[i]);
    printf("\ne: ");
    for(int i=1;i<=n;++i)printf("%15lf ",e[i]);
    printf("\12R2:%15lf,r:%15lf\n",R2,r);
    while(1){
        cin>>u1;
        printf("%15lf\12",bn*u1+an);
    }
    return 0;
}



