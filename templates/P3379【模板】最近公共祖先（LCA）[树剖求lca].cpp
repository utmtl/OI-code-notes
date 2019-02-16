//sorry, 会树剖就是可以为所欲为.jpg
#include<cstdio>
#define in inline
#define re register
#define ll long long
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-') b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return b?-s:s;
}
const int N=500001;
int n,m,root;
struct edge{
	int t,nxt;
}e[N*2];
int cnt,head[N];
int id[N],f[N],d[N],subt[N],son[N],top[N];
in void add(int f,int t)
{
	++cnt;
	e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;
	++cnt;
	e[cnt].t=f,e[cnt].nxt=head[t],head[t]=cnt;
}
void dfs1(int now,int fa)
{
	d[now]=d[fa]+1,f[now]=fa,subt[now]=1;
	int maxson=0;
	for(re int i=head[now];i;i=e[i].nxt)
	{
		if(e[i].t==fa) continue;
		dfs1(e[i].t,now);
		subt[now]+=subt[e[i].t];
		if(subt[e[i].t]>maxson) maxson=subt[e[i].t],son[now]=e[i].t;
	}
}
void dfs2(int now,int topfa)
{
	++cnt;
	id[now]=cnt,top[now]=topfa;
	if(!son[now]) return;
	dfs2(son[now],topfa);
	for(re int i=head[now];i;i=e[i].nxt)
		if(e[i].t!=f[now] && e[i].t!=son[now]) dfs2(e[i].t,e[i].t);
}
in int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]]) x^=y,y^=x,x^=y;
		x=f[top[x]];
	}
	if(d[x]<d[y]) x^=y,y^=x,x^=y;
	return y;
}
signed main()
{
	n=read(),m=read(),root=read();
	for(re int i=1;i<=n-1;++i){int u=read(),v=read();add(u,v);}
	dfs1(root,0);
	cnt=0;
	dfs2(root,root);
	for(re int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		printf("%d\n",lca(x,y));
	}
	return 0;
}
