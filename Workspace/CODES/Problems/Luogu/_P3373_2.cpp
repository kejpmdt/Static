#include<cstdio>
#include<cmath>
#define belong(x) ((x-1)/sqrtn+1)
#define begin(x) ((x-1)*sqrtn+1)
#define end(x) (x*sqrtn)
using namespace std;
long long num[200005];
long long timestag[1000],addtag[1000],sum[1000];

int main(){
	long long n,m,p;
	long long sqrtn;
	scanf("%lld%lld%lld",&n,&m,&p);
	sqrtn=sqrt(n);
	long long i;
	for(i=1;i<=n;++i){
		scanf("%lld",&num[i]);
		sum[belong(i)]+=num[i];
		sum[belong(i)]+=p%=p;
	}
	for(i=1;i<=belong(n);++i)timestag[i]=1;
	long long x,y,k,opt;
	long long ans;
	while(m--){
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1){
			scanf("%lld",&k);
			if(belong(x)==belong(y)){
				for(i=begin(belong(x));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				for(i=x;i<=y;++i){
					sum[belong(i)]-=num[i];
					num[i]*=k;
					sum[belong(i)]+=num[i];
					sum[belong(i)]+=p%=p;
					num[i]+=p%=p;
				}
			}
			else{
				for(i=begin(belong(x));i<=end(belong(x));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				for(i=begin(belong(y));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(y)]=0;
				timestag[belong(y)]=1;
				for(i=x;i<=end(belong(x));++i){
					sum[belong(i)]-=num[i];
					num[i]*=k;
					sum[belong(i)]+=num[i];
					sum[belong(i)]+=p%=p;
					num[i]+=p%=p;
				}
				for(i=begin(belong(y));i<=y;++i){
					sum[belong(i)]-=num[i];
					num[i]*=k;
					sum[belong(i)]+=num[i];
					sum[belong(i)]+=p%=p;
					num[i]+=p%=p;
				}
				for(i=belong(x)+1;i<belong(y);++i){
					sum[i]*=k;
					addtag[i]*=k;
					timestag[i]*=k;
					sum[i]+=p%=p;
					addtag[i]+=p%=p;
					timestag[i]+=p%=p;
				}
			}
		}
		if(opt==2){
			scanf("%lld",&k);
			if(belong(x)==belong(y)){
				for(i=begin(belong(x));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				for(i=x;i<=y;++i){
					sum[belong(i)]+=k;
					num[i]+=k;
					num[i]+=p%=p;
					sum[belong(i)]+=p%=p;
				}
			}
			else{
				for(i=begin(belong(x));i<=end(belong(x));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				for(i=begin(belong(y));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				addtag[belong(y)]=0;
				timestag[belong(y)]=1;
				for(i=x;i<=end(belong(x));++i){
					sum[belong(i)]+=k;
					num[i]+=k;
					num[i]+=p%=p;
					sum[belong(i)]+=p%=p;
				}
				for(i=begin(belong(y));i<=y;++i){
					sum[belong(i)]+=k;
					num[i]+=k;
					num[i]+=p%=p;
					sum[belong(i)]+=p%=p;
				}
				for(i=belong(x)+1;i<belong(y);++i){
					sum[i]+=sqrtn*k;
					addtag[i]+=k;
					sum[i]+=p%=p;
					addtag[i]+=p%=p;
				}
			}
		}
		if(opt==3){
			ans=0;
			if(belong(x)==belong(y)){
				for(i=begin(belong(x));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				for(i=x;i<=y;++i){
					ans+=num[i];
					ans+=p%=p;
				}
			}
			else{
				for(i=begin(belong(x));i<=end(belong(x));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				for(i=begin(belong(y));i<=end(belong(y));++i){
					num[i]*=timestag[belong(i)];
					num[i]+=addtag[belong(i)];
					num[i]+=p%=p;
				}
				addtag[belong(x)]=0;
				timestag[belong(x)]=1;
				addtag[belong(y)]=0;
				timestag[belong(y)]=1;
				for(i=x;i<=end(belong(x));++i){
					ans+=num[i];
					ans+=p%=p;
				}
				for(i=begin(belong(y));i<=y;++i){
					ans+=num[i];
					ans+=p%=p;
				}
				for(i=belong(x)+1;i<belong(y);++i){
					ans+=sum[i];
					ans+=p%=p;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}				



