//���������������ҽ���һ��·��������ͨ,������������,ֻҪ�ж��ǲ���������
//��������:1.�޻� 2.���ҽ���һ�����ڵ�  ע��:��treeҲ������ĿҪ��! 
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
	if(r1==r2) flag=0; //�������Ѿ���ͬһ���µĶ���,�����ͳɻ��� 
	else f[r1]=r2,s--; //�ϲ��ɹ�����ڵ����-- 
}
int main()
{
	long long u,v;
	while(std::cin>>u>>v){
		if(u==-1 && v==-1) break;
		if(u==0 && v==0){
			printf("Yes\n");
			continue;
		} //��treeҲ����,Ҫ���� 
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		flag=1;
		f[v]=v;
		//f[u]=u; 
		f[u]=v;
		s=2;
		b[u]=b[v]=1;
		//��ʼ��ͷ�����ڵ� 
		s--; //ͷ���ڵ�϶�����ɻ� 
		while("too young"){
			scanf("%d%d",&u,&v);
			if(u==0 && v==0) break;
			if(b[u]==0) f[u]=u,b[u]=1,s++;
			if(b[v]==0) f[v]=v,b[v]=1,s++;
			//ÿ�³���һ���ڵ�ͳ�ʼ��һ���ڵ�,b��������Ƿ��ѳ��ֹ� 
			//ÿ�³���һ���ڵ����������++ 
			un(u,v);
		}
		if(flag==1 && s==1) printf("Yes\n"); //�޻�&&���ҽ���һ�����ڵ� 
		else printf("No\n");
	}
	return 0;
}
