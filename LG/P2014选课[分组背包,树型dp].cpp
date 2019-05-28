#include<cstdio>
#include<cstring>
#define re register
#define in inline
in int read()
{
	int s(0),b(0);char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	if(b) return -s;
	return s;
}
in int max(int a,int b){if(a>b)return a;return b;}
struct edge{int t,nxt;}e[301];
int head[301],cnt;
in void add(int f,int t){++cnt,e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;}
int n,m,s[301],f[301][301];
void dp(int now)
{
	for(re int i=head[now];i;i=e[i].nxt)
	{
		int v=e[i].t;
		dp(v);
		for(re int t=m;t>=0;--t)//循环组内(即一个节点的子树中)物品(即子节点)
			for(re int j=t;j>=0;--j)//循环体积(即选择课程的数目)
				f[now][t]=max(f[now][t],f[now][t-j]+f[v][j]);
	}
	if(now!=0)
		for(re int t=m;t>0;--t) f[now][t]=f[now][t-1]+s[now];//除根节点外, 其他节点都必须选修自身并获得相应学分才能选子树中的课程
}
signed main()
{
	n=read(),m=read();
	for(re int i=1;i<=n;++i)
	{
		int x=read();
		add(x,i);
		s[i]=read();
	}
	dp(0);//虚拟一个没有先修课和学分的根节点0方便处理
	int ans=0;
	for(re int j=0;j<=m;++j) if(f[0][j]>ans) ans=f[0][j];
	printf("%d\n",ans);
	return 0;	 
}
