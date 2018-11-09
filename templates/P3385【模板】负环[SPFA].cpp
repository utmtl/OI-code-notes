/*
  多组数据时, 千万记得要清空所有数组!!!
  不要naive地认为它们会被覆盖掉!
  总有你考虑不到的玄学情况!!!
  ---分割线---
  SPFA原理: 先把源点入队, 扫描所有出边并尝试松弛, 松弛成功的点就入队, 再次用它们去更新别的点.(类似与bfs) 注意已经在队列中的点不用再次入队, 反正它们即将被更新, 不用再次入队等待更新.
  SPFA判断负环原理: 用s[i]统计源点到i点的最短路长度, 若 到一个点的最短路长度 >= 节点数 ,就可以判断存在负环.
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define re register
#define int long long
#define in inline
#define debug printf("line %d\n",__LINE__)
using namespace std;
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
int T,n,m;
struct edge{
	int t,w,next;
}e[6100];
int head[3100],cnt=0;
in void add(int f,int t,int w)
{
	++cnt;
	e[cnt].t=t;
	e[cnt].w=w;
	e[cnt].next=head[f];
	head[f]=cnt;
}
queue<int> q;
int b[3100],dis[3100],s[3100];
in bool spfa()
{
	while(!q.empty()) q.pop();
	memset(s,0,sizeof(s));
	memset(b,0,sizeof(b));
	for(re int i=1;i<=n;++i) dis[i]=2147483647;
	dis[1]=0;
	b[1]=1;
	q.push(1);
	s[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		b[u]=0;
		for(re int i=head[u];i;i=e[i].next)
		{
			int v=e[i].t,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!b[v])
				{
					b[v]=1;
					q.push(v);
				}
				s[v]=s[u]+1;//统计路径长度
				if(s[v]>=n) return 1;
			}
		}
	}
	return 0;
}
signed main()
{
	T=read();
	int f,t,w;
	for(re int _=1;_<=T;++_)
	{
		n=read();
		m=read();
		cnt=0;
		memset(head,0,sizeof(head));//head也要清空!!!
		memset(e,0,sizeof(e));//记得清空next值!我们通过next==0判断遍历结束,细思极恐...
		for(re int i=1;i<=m;++i)
		{
			f=read();
			t=read();
			w=read();
			if(w<0) add(f,t,w);
			else{
				add(f,t,w);
				add(t,f,w);
			}
		}
		if(spfa()) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}
