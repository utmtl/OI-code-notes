/*
可以发现选了一个点后(染黑),他连着的点全都不能选了(染白). 又要求封锁所有道路,所以转化成图的黑白染色问题来做.
*/
#include<cstdio>
#define re register
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
struct edge{
	int t,w,next;
}e[110000];
int head[11000],cnt=0,n,m;
inline void add(int f,int t,int w)
{
	++cnt;
	e[cnt].t=t;
	e[cnt].w=w;
	e[cnt].next=head[f];
	head[f]=cnt;
}
int b[11000],c[11000];
int flag,ans,s;
void dfs(int i,int color)
{
	if(flag) return;
	if(b[i])
	{
		if(c[i]!=color) {flag=233;return;}
		//如果i点已染色, 又将染上一个不同的颜色, 则此联通块不可黑白染色.
		else return;
	}
	++cnt;
	b[i]=1;
	c[i]=color;
	if(color) ++s;//统计黑点数
	for(re int v=head[i];v;v=e[v].next)
		dfs(e[v].t,!color);//把相邻的点都染成不同的颜色
	//由于只要求出一种染色方案, 不需要回溯.
}
int main()
{
	n=read();
	m=read();
	int x,y;
	for(re int i=1;i<=m;++i)
	{
		x=read();
		y=read();
		add(x,y,1);
		add(y,x,1);
	}
	for(re int i=1;i<=n;++i)
	{//图并不保证联通, 所以要分别染色各个联通块.
		if(b[i]) continue;
		flag=0;
		s=0;//s统计此联通块黑点个数
		cnt=0;//cnt用来统计此联通块节点总数
		dfs(i,1);
		if(flag==233){
			printf("Impossible\n");
			return 0;
		}
		ans+=s<(cnt-s)?s:(cnt-s);
		//既然节点i染黑可行,那么黑白互换也可行.取这两种方案中最小的.
	}
	printf("%d\n",ans);
	return 0;
}
