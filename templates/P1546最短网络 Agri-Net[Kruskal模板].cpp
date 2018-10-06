/*��³˹����ģ�� 
Kruskal�㷨����:
(1)��ͼG����һ��ɭ�֣�ÿ������Ϊһ�ö�������
(2)�����еı߼��뼯��S����һ��ʼS = E
(3)��S���ó�һ����̵ı�(u,v)�����(u,v)����ͬһ�����ڣ�������u,v�ϲ�����������ͬʱ��(u,v)�����������ı߼�E'
(4)�ظ�(3)ֱ�����е�����ͬһ�������߼�E'����һ����С������
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
}e[99999]; //�߼�����洢 
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
			if(r1!=r2){ //�������ɻ� 
				ans+=e[i].w;
				j++;
				fa[r1]=r2; //ѡ�����ߣ��������������� 
			}
			if(j==n-1) break; //��С��������n-1���ߣ��õ�n-1�����˳� 
		}
		printf("%d\n",ans);
		memset(e,0,sizeof(e));
		cnt=0;
	}
	return 0;
}
//�����ִ���Ű棬��������
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
