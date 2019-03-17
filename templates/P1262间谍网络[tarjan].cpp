#include<cstdio>
#define re register
#define in inline
#define int long long
in int read()
{
    int s=0,b=0;char ch;
    do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return b?-s:s;
}
int n,p,m;
struct edge{int t,nxt;}e[500001];
int head[100001],cnt;
in void add(int f,int t){++cnt,e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;}
int c[100001],id[100001],low[100001],b[100001],num,val[100001],w[100001],mini[100001];
//c[i]:i点所属强连通分量编号 id:dfs序 low:追溯值 val:强连通分量中的最小费用 mini:强连通分量中的最小编号
int sta[100001],top;
in int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
void tj(int now)
{
	//在一个强连通分量中只要收买最便宜的一个就控制了整个分量, 所以可tarjan缩点
	//缩点后收买所有入度为0的点即可
    id[now]=low[now]=++cnt;
    sta[++top]=now;
    b[now]=1;
    for(re int i=head[now];i;i=e[i].nxt)
    {
        if(!id[e[i].t]){tj(e[i].t);low[now]=min(low[now],low[e[i].t]);}//未访问过则递归tarjan
        else if(b[e[i].t]) low[now]=min(low[now],id[e[i].t]);//构成环
    }
    if(id[now]==low[now])//"分量的根节点"
    {
        ++num;
        int t;		
        do{
            t=sta[top--];
            b[t]=0;
            c[t]=num;
			if(w[t]&&w[t]<val[num]) val[num]=w[t];//求收买分量的费用
			if(t<mini[num]) mini[num]=t;//求分量中最小的编号
        }while(t!=now);//从栈顶到now节点都在这个分量中
    }
}
int rd[100001];//入度
signed main()
{
    n=read(),p=read();
	for(re int i=1;i<=n;++i) mini[i]=val[i]=2147483647;
	int x;
	for(re int i=1;i<=p;++i) x=read(),w[x]=read();
	m=read();
	for(re int i=1;i<=m;++i)
    {
        int u=read(),v=read();
        add(u,v);
    }
    cnt=0;
    for(re int i=1;i<=n;++i) if(!id[i]) tj(i);//tarjan求强连通分量
    cnt=0;
    for(re int i=1;i<=n;++i)//缩点:不同强连通分量之间的边保留, 整个强连通分量化为一点
        for(re int j=head[i];j;j=e[j].nxt)
            if(c[i]!=c[e[j].t]) ++rd[c[e[j].t]];//e[j].t所在的强连通分量入度++
    int ans=0;
    for(re int i=1;i<=num;++i)
	{
		if(!rd[i]) ans+=val[i],b[i]=1;//收买入度为0的点
		if(!rd[i]&&val[i]==2147483647) {printf("NO\n%lld\n",mini[i]);return 0;}//若入度为0的点不能收买,则无解
	}
	printf("YES\n%lld\n",ans);
    return 0;
}
