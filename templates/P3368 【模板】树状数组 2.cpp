/*
�ʴ������޸ĵ���״����ģ�� 

���˼��:
����a[]={1,6,8,5,10}, ��ô�������b[]={1,5,2,-3,5}
��b[i]=a[i]-a[i-1];(a[0]=0;), ��ô��֤a[i]=b[1]+....+b[i];

������[2,4]����2
a�����Ϊa[]={1,8,10,7,10}, b�����Ϊb={1,7,2,-3,3};
b����ֻ��b[2]��b[5]����, ��Ϊ����[2,4]��ͬʱ����2��, ������������b[i]-b[i-1]�ǲ����

���Զ�����[x,y]�����޸�,ֻ���޸�b[x]��b[y+1]:
��
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
inline void add(int i,int x)//����add 
{
	while(i<=n)
	{
		cf[i]+=x;
		i+=lowbit(i);
	}
}
inline void add_qj(int i,int j,int x)//[i,j]����+x 
{
	add(i,x);
	add(j+1,-x);
}
inline int sum(int i)//��1~i��ǰ׺�ͼ�Ϊa[i]��ֵ 
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
	}//���ö���һ����ɨһ��,ֱ�ӱ߶������������ 
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
