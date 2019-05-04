#include<cstdio>
#define re register
#define in inline
#define db double
#define int long long
int n,m,v,e,c[2021],d[2021];
db k[2021],f[2021][2021][2];
int dis[301][301];
in int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
in db min(db a,db b)
{
    if(a<b) return a;
    return b;
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&v,&e);
    for(re int i=1;i<=n;++i) scanf("%lld",&c[i]);
    for(re int i=1;i<=n;++i) scanf("%lld",&d[i]);
    for(re int i=1;i<=n;++i) scanf("%lf",&k[i]);
    for(re int i=1;i<=v;++i)
        for(re int j=1;j<=v;++j)
            if(i!=j) dis[i][j]=2147483647;//注意dis[x][x]=0!!!
    for(re int i=1;i<=e;++i)
    {
        int t1,t2,w;
        scanf("%lld%lld%lld",&t1,&t2,&w);
        if(w<dis[t1][t2]&&t1!=t2) dis[t2][t1]=dis[t1][t2]=w;//小心重边和自环
    }
    for(re int k=1;k<=v;++k)
        for(re int i=1;i<=v;++i)
            for(re int j=1;j<=v;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(re int i=1;i<=n;++i)
        for(re int j=0;j<=m;++j)
            f[i][j][0]=f[i][j][1]=2147483647.0;
    f[1][0][0]=f[1][1][1]=0;//记得初始化!!!
    for(re int i=2;i<=n;++i)
    {
        int sqcs=min(m,i);
        for(re int j=0;j<=sqcs;++j)//注意一次都不申请也可以
        {
            f[i][j][0]=min(f[i-1][j][1]+k[i-1]*dis[d[i-1]][c[i]]+(1.0-k[i-1])*dis[c[i-1]][c[i]],f[i-1][j][0]+dis[c[i-1]][c[i]]);
            if(j) f[i][j][1]=min(f[i-1][j-1][1]+k[i-1]*k[i]*dis[d[i-1]][d[i]]+k[i-1]*(1.0-k[i])*dis[d[i-1]][c[i]]+(1.0-k[i-1])*k[i]*dis[c[i-1]][d[i]]+(1.0-k[i-1])*(1.0-k[i])*dis[c[i-1]][c[i]],f[i-1][j-1][0]+k[i]*dis[c[i-1]][d[i]]+(1.0-k[i])*dis[c[i-1]][c[i]]);
        //注意j-1不能为负
        }
    }
    db ans=2147483647.0;
    for(re int i=0;i<=m;++i)//记得在所有的申请次数中取min
        ans=min(ans,f[n][i][0]),ans=min(ans,f[n][i][1]);
    printf("%0.2lf\n",ans);
    return 0;
}
