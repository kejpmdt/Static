#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("T1.in","r",stdin);
    freopen("T1.out","w",stdout);
    int ans=0;
    string s;
    string a;
    int n,q;
    scanf("%d%d",&n,&q);
    cin>>s;
    bool pd;
    while(q--){
        cin>>a;
        ans=0;
        for(int i=0;i<n-9;++i){
            pd=true;
            for(int j=0;j<10;++j){
                if(s[i+j]!=a[j]&&a[j]!='?'){
                    pd=false;
                    break;
                }
            }
            if(pd)++ans;
        }
        cout<<ans<<'\12';
    }
    return 0;
}

