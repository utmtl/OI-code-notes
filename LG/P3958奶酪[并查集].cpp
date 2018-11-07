/*
n很小,考虑暴力
直接每读入一个新点就计算他与已经读入的每个点的距离
用并查集维护球之间的相连关系
若dis<=2r则合并两个球
注意特判存一下与上下表面相连的球
最后枚举与上下表面相连的球的两两组合, 若其中有一对在同一集合内则Yes
*/
#include<cstdio>
#define re register
#define in inline
#define int long long
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
in int dis(int x1,int y1,int z1,int x2,int y2,int z2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
	//dis的平方
}
int T,n,h,r;
int f[1100];
struct node{
	int x,y,z;
}a[1100];
int up[1100],down[1100],cntu,cntd;
//up,down分别存储与上表面,下表面相连的点的序号
int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
in void u(int r1,int r2)
{
	f[r1]=r2;
}
signed main()
{
	T=read();
	for(re int _=1;_<=T;++_)
	{
		n=read();
		h=read();
		r=read();
		for(re int i=1;i<=n;++i) f[i]=i;
		cntu=0,cntd=0;
		for(re int i=1;i<=n;++i)
		{
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			for(int j=1;j<=i;++j)//注意自己和自己是联通的,j可以等于i
			{
				int t=dis(a[i].x,a[i].y,a[i].z,a[j].x,a[j].y,a[j].z);
				if(t<=4*r*r){//注意dis是距离的平方,省去了sqrt
					int r1=find(i);
					int r2=find(j);
					if(r1!=r2) u(r1,r2);
				}
			}
			if(a[i].z<=r) down[++cntd]=i;
			if(a[i].z>=h-r) up[++cntu]=i;
		}
		int flag=1;
		for(re int i=1;i<=cntd;++i)
		{
			for(re int j=1;j<=cntu;++j)
			{
				int r1=find(down[i]),r2=find(up[j]);
				if(r1==r2){
					printf("Yes\n");
					flag=0;
					break;
				}
			}
			if(!flag) break;//注意一旦找到可行解就要完全break出双层循环, 不然若有多解就会输出多个Yes
		}
		if(flag) printf("No\n");
	}
	return 0;
}
