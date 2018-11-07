/*
这道题要求最大收费点的最小值,明显是二分答案
二分check(maxf)函数目标:判断能否在 最大收费点小于maxf 的条件下,走到终点
能则缩小maxf, 否则只能是更大的maxf
具体实现: dijkstra松弛的时候加个判断 点权小于maxf 就行了
*/
#include<cstdio>
#include<queue>
#define re register
#define int long long
//十年竞赛一场空
//没开longlong见祖宗
//总有你想不到的地方炸了int
using namespace std;
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
}//快读是不可能出锅的
struct edge{
	int t,w,next;
}e[510000];
int head[110000],cnt=0,n,m,b,f[110000];
//十年竞赛一场空
//数组开小见祖宗
//别吝啬空间!
//总有你想不到的地方炸了你的数组
inline void add(int f,int t,int w)
{
	//printf("%lld\n",cnt);
	//十年竞赛一场空
    //不删DeBug见祖宗
	++cnt;
	e[cnt].t=t;
	e[cnt].w=w;
	e[cnt].next=head[f];
	head[f]=cnt;
}
struct node{
	int dis,num;
	bool operator < (const node & t)const
		{
			return dis>t.dis;
		}
};
priority_queue<node> q;
int dis[11000];
bool dijkstra(int maxf) //返回路径上每个点的权值小于maxf时, 能否走到终点
{
	//标准dijkstra, 只是在松弛时加入了节点的权值不能超过maxf的条件
	//这样就可以保证求出 经过的节点的权值都不超过maxf 条件下的最短路
	if(f[1]>maxf) return false; //注意题目说起点也要算花费
	for(re int i=1;i<=n;i++) dis[i]=2147483647;
	node x;
	x.num=1;
	x.dis=0;
	dis[1]=0;
	q.push(x);
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		int u=x.num;
		if(x.dis!=dis[u]) continue;
		for(re int i=head[u];i;i=e[i].next)
		{
			int v=e[i].t,w=e[i].w;
			if(dis[u]+w<dis[v] && f[v]<=maxf)
			{
				dis[v]=dis[u]+w;
				node x1;
				x1.num=v;
				x1.dis=dis[v];
				q.push(x1);
			}
		}
	}
	if(dis[n]>=b) return false;
	//如果求出来1到n的最短路长度大于血量
	//则不能做到使 路径上每个点的权值都不超过maxf
	else return true;
}
signed main()
{
	n=read();
	m=read();
	b=read();
	int x,y,z;
	int l=2147483647,r=0;
	for(re int i=1;i<=n;++i)
	{
		f[i]=read();
		if(f[i]<l) l=f[i];
		if(f[i]>r) r=f[i];
	}//预处理出二分的区间:最小点权~最大点权
	for(re int i=1;i<=m;++i)
	{
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
		//注意是无向图
	}
	if(!dijkstra(2147483647)){
		printf("AFK\n");
		//无限制的情况下,如果不能从起点走到终点,肯定输出 啊♂FUCK
		return 0;
	}
	//下面就是标准二分
	while(l<r)
	{
		int mid=(l+r)/2;
		if(!dijkstra(mid)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
