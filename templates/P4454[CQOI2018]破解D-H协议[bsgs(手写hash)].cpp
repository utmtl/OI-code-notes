#include<cstdio>
#include<cmath>
#include<cstring>
#define re register
#define in inline
#define int long long
int g,p,n;
int ksm(int a,int k,int yyb)
{
    int ans=1;
    while(k)
    {
        if(k&1) ans=ans*a%yyb;
        a=a*a%yyb;
        k>>=1;
    }
    return ans;
}
const int jzm=51347;
int hs[jzm],head[jzm],nxt[jzm],val[jzm],cnt;
void insert(int key,int v)
{
    int k=key%jzm;
    hs[cnt]=key,val[cnt]=v,nxt[cnt]=head[k],head[k]=cnt++;
}
int find(int key)
{
    int k=key%jzm;
    for(re int i=head[k];i!=-1;i=nxt[i])
        if(hs[i]==key) return val[i];
    return -1;
}
int bsgs(int a,int b,int yyb)
{
    cnt=0;
    memset(head,-1,sizeof(head));
    b%=yyb;
    int t=sqrt(yyb)+1,s=1;
    for(re int i=0;i<t;++i){insert(b*s%yyb,i);s=s*a%yyb;}
    a=s%yyb;
    s=1;
    for(re int i=0;i<=t;++i)
    {
        int v=find(s);
        if(v!=-1&&i*t-v>=0) return i*t-v;
        s=s*a%yyb;
    }
}
signed main()
{
    scanf("%lld%lld%lld",&g,&p,&n);
    for(re int i=1;i<=n;++i)
    {
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",ksm(b,bsgs(g,a,p),p));
    }
    return 0;
}
