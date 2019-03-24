// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#define in inline
#define re register
#define int long long
int yyb,n;
struct mat{
    int v[4][4];
    mat operator*(const mat &b)const
        {
            mat c;
            memset(c.v,0,sizeof(c.v));
            for(re int i=1;i<=3;++i)
                for(re int j=1;j<=3;++j)
                    for(re int k=1;k<=3;++k)
                        c.v[i][j]=(c.v[i][j]+(v[i][k]%yyb)*(b.v[k][j]%yyb))%yyb;
            return c;
        }
}s,t,I;
in mat ksm(mat ba,int p)
{
    mat ans=I;
    while(p)
    {
        if(p&1) ans=ans*ba;
        ba=ba*ba;
        p>>=1;
    }
    return ans;
}
signed main()
{
    scanf("%lld%lld",&n,&yyb);
    I.v[1][1]=I.v[2][2]=I.v[3][3]=1,s.v[1][1]=s.v[1][3]=1,s.v[1][2]=2;
    t.v[1][1]=10,t.v[2][1]=t.v[2][2]=t.v[3][2]=t.v[3][3]=1;
    re int i;
    //分段进行矩阵加速递推即可 s_n+1=s_n*c(i)+i c(i)为i的位数, 依次取1~最大18
    for(i=10;i<=n;i*=10)
    {
        if(i==10) s=s*ksm(t,i-i/10-1);
        else s=s*ksm(t,i-i/10);
        t.v[1][1]=t.v[1][1]*10%yyb;
    }
    if(i!=n) s=s*ksm(t,n-i/10+1);//剩余部分
    printf("%lld\n",s.v[1][1]);
    return 0;
}
