/*克鲁斯卡尔模板 
Kruskal算法流程:
(1)将图G看做一个森林，每个顶点为一棵独立的树
(2)将所有的边加入集合S，即一开始S = E
(3)从S中拿出一条最短的边(u,v)，如果(u,v)不在同一棵树内，则连接u,v合并这两棵树，同时将(u,v)加入生成树的边集E'
(4)重复(3)直到所有点属于同一棵树，边集E'就是一棵最小生成树
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
int fa[999],n,cnt=0;
struct edge{
	long long f,t,w;
	bool operator < (const edge &that)const{
		if(w<that.w) return true;
		else return false;
	}
}e[99999]; //边集数组存储 
inline int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
inline void u(int r1,int r2){
	fa[r1]=r2;
}
int main()
{
	while(std::cin>>n){
		int x;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&x);
				e[++cnt].w=x;
				e[cnt].f=i;
				e[cnt].t=j;
			}
		}
		std::sort(e+1,e+1+cnt);
		int j=0,ans=0;
		for(int i=1;;i++)
		{
			int r1=find(e[i].f);
			int r2=find(e[i].t);
			if(r1!=r2){ //不能连成环 
				ans+=e[i].w;
				j++;
				fa[r1]=r2; //选这条边，并连接这两个点 
			}
			if(j==n-1) break; //最小生成树共n-1条边，得到n-1条就退出 
		}
		printf("%d\n",ans);
		memset(e,0,sizeof(e));
		cnt=0;
	}
	return 0;
}
//初中手打快排版，留作纪念
/*
#include<iostream>
#include<cstring>
using namespace std;
int a[10000][3],fa[101];
int x,tot,k=0,n;
const int maxlongint=0xfffffff;
int find(int poi)
{
	if (fa[poi]!=poi) fa[poi]=find(fa[poi]);
	return fa[poi];
}
void kp(int l,int r)
{
	int i,j,t,m;
	i=l;
	j=r;
	m=a[(l+r)/2][0];
	do{
		while(a[i][0]<m) i++;
		while(a[j][0]>m) j--;
		if(i<=j)
		{
			t=a[i][1];
			a[i][1]=a[j][1];
			a[j][1]=t;
			t=a[i][2];
			a[i][2]=a[j][2];
			a[j][2]=t;
			t=a[i][0];
			a[i][0]=a[j][0];
			a[j][0]=t;
			i++;
			j--;
		}
	}while(i<=j);
	if(i<r) kp(i,r);
	if(l<j) kp(l,j);
}
int main()
{
	int i,j,m = 0,ta,tb;
	cin>>n;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
		{
			cin>>x;
			if (x != 0)
			{
				m++;
				a[m][1] = i;
				a[m][2] = j;
				a[m][0] = x;
			}
		}
	for(i=1;i<=n;i++) fa[i] = i;
	kp(1,m);
	k=0;
	for(i=1;k!=n-1;i++)
	{
		ta=find(a[i][1]);
		tb=find(a[i][2]);
		if(ta!=tb)
		{
			fa[tb]=ta;
			k++;
			tot+=a[i][0];
		}
	}
	cout<<tot;
	return 0;
}
*/
