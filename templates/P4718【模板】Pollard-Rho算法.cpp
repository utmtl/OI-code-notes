#include<cstdio>
#include<time.h>
#include<cstdlib>
#define re register
#define in inline
#define int long long
in int ksm(int a,int b,int yyb)
{
    int ans=1;
    while(b){
        if(b&1)	ans=ans*a%yyb;
        a=a*a%yyb;
        b>>=1;
    }
    return ans;
}
in int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
in int pr(int n)
{
    re int x0=rand()%(n-1)+1,x1=x0,r,c=rand()%(n-1)+1,s=1;
	//设x0为环的起点, x1为当前枚举的点
	//记得初始化x0,x1和s!!!
    for(re int k=2;;k<<=1,x0=x1,s=1)//假设环的长度为k, 若k步内x1没有走回x0则k加倍
    {
        for(re int i=1;i<=k;++i)
        {
            x1=(__int128)x1*x1%n+c;//x1的生成函数: x^2+c(mod n)
            s=(__int128)s*(x1-x0+n)%n; //(x1-x0+n)%n 展开即 abs(x1-x0)%n
            if(i%127==0)//s累积差的乘积, 每127个差一起与n求一次gcd, 减少gcd次数
            {
                r=gcd(s,n);
                if(r>1) return r;
				//找到环时, x0==x1, 则s=0, 求得r=n, 返回n, 退出整个函数
            }
        }
        r=gcd(s,n);//别漏掉不满127个的情况
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
            r=r*r%x;
            if(r==x-1) break;
        }
        if(j>t) return false;
    }
    return true;
}
in int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int ans;
void ask(int n)
{
    if(n<=ans) return;//最优化剪枝
    if(mr(n)) {ans=max(ans,n);return;}
    int t=n;
    while(t==n) t=pr(t);//找到环时返回n, 重新进行一遍(重新rand c,x0,x1)
    while(n%t==0) n/=t;//除掉所有因子t
    ask(t);//继续分解
    ask(n);
}
signed main()
{
    srand(time(NULL));
    int n,x;
    scanf("%lld",&n);
    for(re int i=1;i<=n;++i)
    {
        ans=1;
        scanf("%lld",&x);
        ask(x);
        if(x==ans) printf("Prime\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
