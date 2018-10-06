//带权并查集 
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int f[210000],sum[210000]; //注意：取名rank有玄学错误！ 
map<string,int> mmp; //表达对出题人崇高的敬意 （不是指我的教练） 
//注意把名字映射成编号 
int m;
int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
inline int u(int r1,int r2)
{
	f[r2]=r1;
	sum[r1]+=sum[r2]; //在合并时把儿子的节点数加入父亲的节点数即可完成元素数统计 
	return sum[r1];
}
int main()
{
	string r1,r2;
	int t;
	scanf("%d",&t);
	while(t-->0){
		int cnt=0;
		scanf("%d",&m);
		for(int i=1;i<210000;i++) f[i]=i,sum[i]=1; //m个朋友关系最多有m*2个人！不是m个人！ 
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
	return 0;
}
