#include<cstdio>
#define re register
#define in inline
#define int long long
int n,m;
struct edge{
	int t,w,nxt;
}e[200002];
int head[50001],cnt,dis[50001];
in void add(int f,int t,int w){e[++cnt].t=t,e[cnt].w=w,e[cnt].nxt=head[f],head[f]=cnt;}
int base[64];
in void insert(int x)
{
	for(re int i=63;i>=0;--i)
	{
		int t=x&(1ll<<i);
		if(!t) continue;
		if(!base[i]){base[i]=x;break;}
		x^=base[i];
	}
}
void dfs(int now)
{
	for(re int i=head[now];i;i=e[i].nxt)
	{
		int v=e[i].t;
		if(dis[v]) insert(dis[now]^e[i].w^dis[v]);
		else{
			dis[v]=dis[now]^e[i].w;
			dfs(v);
		}
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(re int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dfs(1);
	for(re int i=63;i>=0;--i)
		if((dis[n]^base[i])>dis[n]) dis[n]^=base[i];
	printf("%lld\n",dis[n]);
	return 0;
}
