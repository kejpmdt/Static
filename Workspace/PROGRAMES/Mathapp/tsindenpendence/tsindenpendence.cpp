#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        double ans;
        ans=(a+b+c+d)*(a*d-b*c)*(a*d-b*c);
        ans/=((a+b)*(c+d)*(a+c)*(b+d));
        printf("%.15lf\12",ans);
    }
}
