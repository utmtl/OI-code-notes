#include<cstdio>
#include<map>
using namespace std;
int n,k,l;
int fg[200000],ft[200000];
map<pair<int,int>,int> s;
int findg(int x)
{
	if(fg[x]!=x) fg[x]=findg(fg[x]);
	return fg[x];
}
void ug(int r1,int r2)
{
	fg[r2]=r1;
}
int findt(int x)
{
	if(ft[x]!=x) ft[x]=findt(ft[x]);
	return ft[x];
}
void ut(int r1,int r2)
{
	ft[r2]=r1;
}
int main()
{
	int r1,r2;
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n;i++) fg[i]=ft[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&r1,&r2);
		r1=findg(r1);
		r2=findg(r2);
		if(r1!=r2) ug(r1,r2);
	}
	for(int i=1;i<=l;i++)
	{
		scanf("%d%d",&r1,&r2);
		r1=findt(r1);
		r2=findt(r2);
		if(r1!=r2) ut(r1,r2);
	}
	for(int i=1;i<=n;i++)
	{
		findg(i);
		findt(i);
	}
	//首先把问题数据用并查集处理为一个个联通块，
	//要 求既通过公路连通又通过铁路连通的城市数 就转化为了 求各fg与ft的交集元素数 
	//所以只需用map统计每个交集中点的数量即可
	for(int i=1;i<=n;i++)
	{
		s[{fg[i],ft[i]}]++;
		//如果两个点之间既能走公路到达，又能走铁路到达，他们肯定属于同一个交集，那么fg[i]与ft[i]的交集元素数+1 
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",s[{fg[i],ft[i]}]);
	}
	return 0;
}
