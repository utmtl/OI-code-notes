#include<cstdio>
#include<algorithm>
#define int long long
#define re register
using namespace std;
inline int read()
{
    int s=0,b=1;
    char ch;
    do{
        ch=getchar();
        if(ch=='-') b=-1;
    }while(ch<'0' || ch>'9');
    while(ch>='0' && ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return b*s;
}
int n,m;
struct edge{//用边集数组存储比较方便
    int f,t,w;
    bool operator < (const edge &t)const
        {
            return w<t.w;
        }//注意给边排序要重载<运算符或者自定义cmp函数
}e[600000];
int cnt=0,f[600000];
int find(int x)
{
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}
inline void u(int r1,int r2)
{
    f[r1]=r2;
}
int ans;
signed main()
{
    n=read();
    m=read();
    for(re int i=1;i<=m;++i)
    {
        e[i].f=read();
        e[i].t=read();
        e[i].w=read();
    }
    sort(e+1,e+m+1);
    for(re int i=1;i<=n;++i) f[i]=i;
    /*
    克鲁斯卡尔算法思想:
    每次选取最短的边加入最小生成树, 并且这条边不能使树出现环
    利用一个并查集维护点之间的关系, 防止形成环
    */
    for(re int i=1;i<=m;++i)
    {
        int r1=find(e[i].f);
        int r2=find(e[i].t);
        if(r1!=r2){//边i连接的两个点不在同一棵树里才能选这条边, 不然会成环
            u(r1,r2);
            ans+=e[i].w;
            ++cnt;
        }
        if(cnt==n-1) break;
    }
    printf("%lld\n",ans);
    return 0;
}
