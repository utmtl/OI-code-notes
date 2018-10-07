#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
long long f[210000],sum[210000]; //注意：取名rank有玄学错误！ 
map<string,int> mmp; //表达对出题人崇高的敬意 （不是指我的教练） 
int m;
int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
inline int u(int r1,int r2)
{
	f[r2]=r1;
	sum[r1]+=sum[r2];
	return sum[r1];
}
int main()
{
	string r1,r2;
	int t;
	while(scanf("%d",&t)!=EOF){ //巨坑，第一行的数字t不是总的测试数据组数，可能有不确定的多组数据，每组都有一个t，每个t下面又有t个n
		while(t-->0){
			int cnt=0;
			scanf("%d",&m);
			for(int i=0;i<=2*m+1;i++) f[i]=i,sum[i]=1; //m个朋友关系最多有m*2个人！不是m个人！ 
			for(int i=1;i<=m;i++)
			{
				cin>>r1>>r2;
				if(mmp.count(r1)==0) mmp[r1]=++cnt;
				if(mmp.count(r2)==0) mmp[r2]=++cnt;
				int x1=find(mmp[r1]);
				int x2=find(mmp[r2]);
				if(x1!=x2) printf("%d\n",u(x1,x2));
				else printf("%d\n",sum[x1]);
			}
			mmp.clear();
		}
	}
	return 0;
}
