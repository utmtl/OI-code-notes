//任意两个房间有且仅有一条路径可以相通,这是树的性质,只要判断是不是树即可
//必须满足:1.无环 2.有且仅有一个根节点  注意:空tree也满足题目要求! 
#include<cstdio>
#include<iostream>
#include<cstring>
long long f[100002],s;
long long flag,b[100002];
inline long long find(long long x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
inline void un(long long r1,long long r2)
{
	r1=find(r1);
	r2=find(r2);
	if(r1==r2) flag=0; //若他们已经是同一根下的儿子,再连就成环了 
	else f[r1]=r2,s--; //合并成功则根节点个数-- 
}
int main()
{
	long long u,v;
	while(std::cin>>u>>v){
		if(u==-1 && v==-1) break;
		if(u==0 && v==0){
			printf("Yes\n");
			continue;
		} //空tree也满足,要特判 
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		flag=1;
		f[v]=v;
		//f[u]=u; 
		f[u]=v;
		s=2;
		b[u]=b[v]=1;
		//初始化头两个节点 
		s--; //头两节点肯定不会成环 
		while("too young"){
			scanf("%d%d",&u,&v);
			if(u==0 && v==0) break;
			if(b[u]==0) f[u]=u,b[u]=1,s++;
			if(b[v]==0) f[v]=v,b[v]=1,s++;
			//每新出现一个节点就初始化一个节点,b用来标记是否已出现过 
			//每新出现一个节点则根的数量++ 
			un(u,v);
		}
		if(flag==1 && s==1) printf("Yes\n"); //无环&&有且仅有一个根节点 
		else printf("No\n");
	}
	return 0;
}
