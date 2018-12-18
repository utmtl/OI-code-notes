#include<cstdio>
#include<cstring>
#define re register
#define in inline
#define int long long
in int read()
{
	int b=1,s=0;
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
const int N=40010;
int __,n,m;
struct edge{
	int t,w,next;
}e[N*2];
int head[N],cnt=0;
in void add(int f,int t,int w)
{
	++cnt;
	e[cnt].t=t;
	e[cnt].w=w;
	e[cnt].next=head[f];
	head[f]=cnt;
}
int log[N],f[N][35],d[N],s[N];
void dfs(int now,int fa)
{
	d[now]=d[fa]+1;
	f[now][0]=fa;
	for(re int i=1;(1<<i)<=d[now];++i)
		f[now][i]=f[f[now][i-1]][i-1];
	for(re int i=head[now];i;i=e[i].next)
	{
		if(e[i].t!=fa){
			s[e[i].t]=s[now]+e[i].w;
			dfs(e[i].t,now);
		}
	}
}
in int lca(int x,int y)
{
	//注意区分d[x]和x
	if(d[x]<d[y]) x^=y,y^=x,x^=y;
	while(d[x]!=d[y]) x=f[x][log[x-y]];
	if(x==y) return x;
	for(re int i=log[d[x]];i>=0;--i)//注意i从log[d[x]]一直循环到0
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0]; //注意是循环到x y父亲相同
}
signed main()
{
	int x=-1;
	for(re int i=1;i<=N;++i)
	{
		if((1<<(x+1))==i) ++x;
		log[i]=x;
	}
	__=read();
	for(re int _=1;_<=__;++_)
	{
		n=read();
		m=read();
		int ff,t,w;
		for(re int i=1;i<=n-1;++i)
		{
			ff=read();
			t=read();
			w=read();
			add(ff,t,w);
			add(t,ff,w);
		}
		dfs(1,0);
		for(re int i=1;i<=m;++i)
		{
			ff=read();
			t=read();
			if(ff==t) printf("0\n");
			else printf("%lld\n",s[ff]+s[t]-2*s[lca(ff,t)]);//注意-2*...
		}
		printf("\n");
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		cnt=0;
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
	}
	return 0;
}
