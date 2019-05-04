#include<cstdio>
#include<queue>
#define in inline
#define int long long
#define re register
using namespace std;
int head[100001],cnt;
struct edge{
    int t,w,nxt;
}e[200002];
in void add(int f,int t,int w){e[++cnt].t=t,e[cnt].w=w,e[cnt].nxt=head[f],head[f]=cnt;}
int n,m,rd[100001],cd[100001];
double f[100001];
queue<int> q;
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(re int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(v,u,w);
        ++rd[u],++cd[u];//注意是在取反后的图上拓补排序, 取反前的图上算概率, 所以入度为取反后的, 出度为取反前的
    }
    //for(re int i=1;i<=n;++i) if(!rd[i]) q.push(i);
    q.push(n);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(re int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].t;
            f[v]+=(f[u]+e[i].w)/cd[v];
            --rd[v];
            if(!rd[v]) q.push(v);
        }
    }
    printf("%0.2lf\n",f[1]);
    return 0;
}
