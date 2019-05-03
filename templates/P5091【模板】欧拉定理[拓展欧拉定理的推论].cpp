#include<cstdio>
#include<cmath>
#define re register
#define in inline
#define int long long
int a,b,m;
in int phi(int n)
{
    int t=sqrt(n),ans=n;//一个数n的所有质因子都小于等于sqrt(n)
    for(re int i=2;i<=t;++i)
    {
        if(n%i==0){
            ans=ans*(i-1)/i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) return ans*(n-1)/n;//n为质数
    else return ans;
}
in int ksm(int ba,int k)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*ba%m;
        k>>=1;
        ba=ba*ba%m;
    }
    return ans;
}
signed main()
{
    scanf("%lld%lld",&a,&m);
    char ch;
    int t=phi(m),s=0,f=0;
    do{ch=getchar();}while(ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9')
    {
        s=s*10+(ch^48),ch=getchar();
        if(s>=t) s%=t,f=1;
    }
    if(f) printf("%lld\n",ksm(a,s+t));
    else printf("%lld\n",ksm(a,s));
    return 0;
}
