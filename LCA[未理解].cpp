#include<cstdio>
#define re register
#define in inline
in int read()
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
int n,m,s;
struct edge{
	int t,next;
}e[500001*2];
int cnt=0,head[500001];
in void add(int f,int t)
{
	++cnt;
	e[cnt].t=t;
	e[cnt].next=head[f];
	head[f]=cnt;
}
int f[500001][100],d[500001];
int log[500001];
void dfs(int now,int fa)
{
	d[now]=d[fa]+1;
	f[now][0]=fa;
	for(re int i=1;(1<<i)<=d[now];++i)
		f[now][i]=f[f[now][i-1]][i-1];
	for(re int i=head[now];i;i=e[i].next)
		if(e[i].t!=fa) dfs(e[i].t,now);
}
in int lca(int x,int y)
{
	if(d[x]<d[y])
	{
		int t=x;
		x=y;
		y=t;
	}//保证x在下
	while(d[x]>d[y]) x=f[x][log[d[x]-d[y]]];
	if(x==y) return x;
	for(re int i=log[d[x]];i>=0;--i)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	//printf("%lf\n",log(1024)/log(2));
	n=read();
	m=read();
	s=read();
	int x,y;
	//for(re int i=1;i<=n;++i) log[i]=log[i-1]+(1<<log[i-1]==i); //求log(x)+1
	int t=1;
	log[1]=0;
	for(re int i=2;i<=n;++i)
	{
		if((1<<(t+1))==i) t++;
		log[i]=t;
		//printf("%d ",k[i]);
	}//预处理出log_2(1~n)的值;
	for(re int i=1;i<=n-1;++i)
	{
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(re int i=1;i<=m;++i)
	{
		x=read();
		y=read();
		printf("%d\n",lca(x,y));
	}
	return 0;
}
