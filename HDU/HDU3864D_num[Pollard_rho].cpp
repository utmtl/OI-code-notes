#include<cstdio>
#include<time.h>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define re register
#define in inline
#define int long long
in int ksm(int a,int b,int yyb)
{
    int ans=1;
    while(b){
        if(b&1) ans=(__int128)ans*a%yyb;
        a=(__int128)a*a%yyb;
        b>>=1;
    }
    return ans;
}
in int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int fa[100000],cnt;
in int pr(int n)
{
    re int x0=rand()%(n-1)+1,x1=x0,r,c=rand()%(n-1)+1,s=1;
    for(re int k=2;;k<<=1,x0=x1,s=1)
    {
        for(re int i=1;i<=k;++i)
        {
            x1=(__int128)x1*x1%n+c;
            s=(__int128)s*(x1-x0+n)%n;
            if(i%127==0)
            {
                r=gcd(s,n);
                if(r>1) return r;
            }
        }
        r=gcd(s,n);
        if(r>1) return r;
    }
}
int qd[6]={2,3,7,61,24251};
in bool mr(int x)
{
    if(x<2) return false;
    if(x==2||x==3||x==7||x==61||x==24251) return true;
    int ba=x-1,r,t=0;
    while(!(ba&1)) ba>>=1,++t;
    for(re int i=0;i<5;++i)
    {
        r=ksm(qd[i],ba,x);
        if(r==1||r==x-1) continue;
        re int j;
        for(j=1;j<=t;++j)
        {
            r=(__int128)r*r%x;
            if(r==x-1) break;
        }
        if(j>t) return false;
    }
    return true;
}
void fj(int n)
{
    if(mr(n)) {fa[++cnt]=n;return;}
    int t=n;
    while(t==n) t=pr(n);
    //while(n%t==0) n/=t;
    fj(n/t);fj(t);
}
signed main()
{
    srand(time(NULL));
    int n;
    while(~scanf("%lld",&n))
    {
        if(n==1||n==0) {printf("is not a D_num\n");continue;}
        cnt=0;
        memset(fa,0,sizeof(fa));
        fj(n);
        if(cnt==2)
        {
            std::sort(fa+1,fa+cnt+1);
            if(fa[1]==fa[2]) printf("is not a D_num\n");
            else printf("%lld %lld %lld\n",fa[1],fa[2],n);
        }
        else if(cnt==3)
        {
            std::sort(fa+1,fa+cnt+1);
            if(fa[1]==fa[2]&&fa[2]==fa[3]) printf("%lld %lld %lld\n",fa[1],fa[1]*fa[1],n);
            else printf("is not a D_num\n");
        }
        else printf("is not a D_num\n");
    }
    return 0;
}
