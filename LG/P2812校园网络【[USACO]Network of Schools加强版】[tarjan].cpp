#include<cstdio>
#define int long long
#define re register
#define in inline
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int n;
struct edge{
	int t,nxt;
}e[5000001];
int head[10001],cnt;
in void add(int f,int t)
{
	++cnt,e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;
}
int dfn[10001],sta[10001],top,low[10001],c[10001],num,b[10001];
int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
void tj(int now)
{
	low[now]=dfn[now]=++cnt,sta[++top]=now,b[now]=1;
	for(re int i=head[now];i;i=e[i].nxt)
	{
		if(!dfn[e[i].t]){tj(e[i].t);low[now]=min(low[now],low[e[i].t]);}
		else if(b[e[i].t]) low[now]=min(low[now],dfn[e[i].t]);
	}
	if(low[now]==dfn[now])
	{
		int t;
		++num;
		do{
			t=sta[top--];
			c[t]=num;
			b[t]=0;
		}while(t!=now);
	}
}
int rd[10001],cd[10001];
signed main()
{
	n=read();
	int u;
	for(re int i=1;i<=n;++i)
	{
		while(1)
		{
			u=read();
			if(!u) break;
			add(i,u);
		}
	}
	cnt=0;
	for(re int i=1;i<=n;++i)
		if(!dfn[i]) tj(i);
	for(re int i=1;i<=n;++i)
		for(re int j=head[i];j;j=e[j].nxt)
			if(c[i]!=c[e[j].t]) ++rd[c[e[j].t]],++cd[c[i]];
	int tr=0,tc=0;
	for(re int i=1;i<=num;++i)
	{
		if(!rd[i]) ++tr;
		if(!cd[i]) ++tc;
	}
	if(num==1) printf("1\n0\n");
	else printf("%lld\n%lld\n",tr,tr>tc?tr:tc);
	return 0;
}
