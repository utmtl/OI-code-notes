#include<cstdio>
#define re register
#define in inline
#define int long long
#define lowbit(i) i&-i
#define dbg printf("line:%d\n",__LINE__)
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int n,order[300001];
struct edge{
	int t,nxt;
}e[300001*2];
int head[300001],cnt;
in void add(int f,int t)
{
	++cnt,e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;
	++cnt,e[cnt].t=f,e[cnt].nxt=head[t],head[t]=cnt;
}
int wid[300001],f[300001],d[300001],id[300001],subt[300001],son[300001],top[300001];
void dfs1(int now,int fa)
{
	d[now]=d[fa]+1,f[now]=fa,subt[now]=1;;
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
	++cnt,id[now]=cnt,top[now]=topfa;
	if(son[now]) dfs2(son[now],topfa);
	else return;
	for(re int i=head[now];i;i=e[i].nxt)
		if(e[i].t!=son[now]&&e[i].t!=f[now]) dfs2(e[i].t,e[i].t);
}
in void adda(int i,int x)
{
	while(i<=n)
	{
		wid[i]+=x;
		i+=lowbit(i);
	}
}
in int sum(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=wid[i];
		i-=lowbit(i);
	}
	return ans;
}
void ask(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]]) x^=y,y^=x,x^=y;
//add id top[x]~id x
		adda(id[top[x]],1);
		adda(id[x]+1,-1);
		x=f[top[x]];
	}
	if(d[x]<d[y]) x^=y,y^=x,x^=y;
	adda(id[y],1);
	adda(id[x]+1,-1);
}
signed main()
{
	n=read();
	for(re int i=1;i<=n;++i) order[i]=read();
	for(re int i=1;i<=n-1;++i) add(read(),read());
	dfs1(1,0);
	cnt=0;
	dfs2(1,1);
	for(re int i=1;i<=n-1;++i)
	{
		ask(order[i],order[i+1]);
		if(i>1){adda(id[order[i]],-1);adda(id[order[i]]+1,1);}
		if(i==n-1){adda(id[order[i+1]],-1);adda(id[order[i+1]]+1,1);}
	}
	for(re int i=1;i<=n;++i) printf("%lld\n",sum(id[i]));
	//for(re int i=1;i<=n;++i) printf("%lld ",wid[i]);
	return 0;
}
