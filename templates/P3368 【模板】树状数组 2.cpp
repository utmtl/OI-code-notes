/*
资瓷区间修改的树状数组模板 

差分思想:
数组a[]={1,6,8,5,10}, 那么差分数组b[]={1,5,2,-3,5}
即b[i]=a[i]-a[i-1];(a[0]=0;), 那么易证a[i]=b[1]+....+b[i];

若区间[2,4]都加2
a数组变为a[]={1,8,10,7,10}, b数组变为b={1,7,2,-3,3};
b数组只有b[2]和b[5]变了, 因为区间[2,4]是同时加上2的, 所以在区间内b[i]-b[i-1]是不变的

所以对区间[x,y]进行修改,只用修改b[x]与b[y+1]:
即
b[x]=b[x]+k;
b[y+1]=b[y+1]-k;
*/
#include<iostream>
#include<cstdio>
using namespace std;
int cf[500100],n,m;
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int i,int x)//单点add 
{
	while(i<=n)
	{
		cf[i]+=x;
		i+=lowbit(i);
	}
}
inline void add_qj(int i,int j,int x)//[i,j]区间+x 
{
	add(i,x);
	add(j+1,-x);
}
inline int sum(int i)//求1~i的前缀和即为a[i]的值 
{
	int ans=0;
	while(i>0)
	{
		ans+=cf[i];
		i-=lowbit(i);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	int t1,t2,x;
	scanf("%d",&x);
	t2=x;
	add(1,x);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		t1=x;
		add(i,x-t2);
		t2=t1;
	}//懒得读入一遍再扫一遍,直接边读入变求差分数组 
	int i1,j1,a;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%d",&i1,&j1,&a);
			add_qj(i1,j1,a);
		}
		else{
			scanf("%d",&i1);
			printf("%d\n",sum(i1));
		}
	}
	return 0;
}
