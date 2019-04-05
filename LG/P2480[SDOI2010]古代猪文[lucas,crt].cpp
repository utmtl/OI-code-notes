#include<cstdio>
#define in inline
#define re register
#define int long long
int q,n,jc[36000],m[5]={0,2,3,4679,35617},a[5];
const int yybp=999911659,yyb=999911658;
in int ksm(int ba,int k,int p)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*ba%p;
        ba=ba*ba%p;
        k>>=1;
    }
    return ans;
}
in int C(int n,int m,int p)
{
    if(n<m) return 0;
    if(!n) return 1;
    return jc[n]*ksm(jc[m],p-2,p)%p*ksm(jc[n-m],p-2,p)%p;
}
in int lucas(int n,int m,int p)
{
    if(n<m) return 0;
    if(!n) return 1;
    return lucas(n/p,m/p,p)%p*C(n%p,m%p,p)%p;
}
in int crt()
{
    int x=0;
    for(re int i=1;i<=4;++i)
        x=(x+a[i]*(yyb/m[i])%yyb*ksm(yyb/m[i],m[i]-2,m[i]))%yyb;
    return x;
}
signed main()
{
    scanf("%lld%lld",&n,&q);
    if(q%yybp==0){printf("0\n");return 0;}
    for(re int i=1;i<=4;++i)
    {
        jc[1]=1,jc[0]=1;
        for(re int j=2;j<=m[i];++j) jc[j]=j*jc[j-1]%m[i];
        for(re int d=1;d*d<=n;++d)
        {
            if(n%d) continue;
            a[i]=(a[i]+lucas(n,d,m[i]))%m[i];
            if(d*d!=n) a[i]=(a[i]+lucas(n,n/d,m[i]))%m[i];
        }	
    }
    printf("%lld\n",ksm(q,crt(),yybp));
    return 0;
}
