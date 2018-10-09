#include<cstdio>
int n,m,c[500001];
inline int lowbit(int x)
{
	return (x&(-x));
}
inline void update(int i,int x) //a[i]+=x; 
{
	/*
	while("I AK IOI"){
		if(i>n) break;
		c[i]+=x;
		i+=lowbit(i);
	}
	*/
	while(i<=n){
		c[i]+=x;
		i+=lowbit(i);
	}
}
inline int sum(int i) //a1+a2+a3+...+ai
{
	int s=0;
	while(i!=0){
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}
int main()
{
	int a,b,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		update(i,a);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&a,&b);
		if(x==1) update(a,b);
		else printf("%d\n",sum(b)-sum(a-1)); //注意：求[x,y]区间和时是a_y的前缀和减a_(x-1)的前缀和 
	}
	return 0;
}
