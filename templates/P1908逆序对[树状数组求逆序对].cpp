/*
��״�����������ģ�� 
����˵,������������ ÿһ������ǰ���м��������Ĵ����,�������ĺ;�������Ե�����
��������Ͱ�ŵ�˼��,a[n]=x�����Ҫ������������������x����Ϊn,=0����û��n 
����һ����״����cά��a��ǰ׺��,�Ϳ���֪��a�е�ÿ����nǰ���м���������С
�����ǵڼ�����(ѭ������i)��ȥǰ��������С�����ĸ���,���ɵ�����ǰ���ж�����������
����ÿ����������Ȼ����������ɵ��������� 
--- 
�����������ݵľ����С�޹�,ֻ������֮�����Դ�С��ϵ�й�,��˿�������ɢ����ֹn����ը����(������Ͱ��) 
*/
//ʮ�꾺��һ����,û��longlong������ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long c[200000],lsh_cp[200000],n,k;
struct node{
	long long id,data;
	bool operator < (const node &that)const
	{
		if(data<that.data) return true;
		else return false;
	}
}lsh[200000];
inline long long lowbit(long long x)
{
	return (x&(-x));
}
inline void add(long long i,long long x)
{
	while(i<=n)
	{
		c[i]+=x;
		i+=lowbit(i);
	}
}
inline long long sum(long long i)
{
	long long ans=0;
	while(i>=1)
	{
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
inline long long max(long long x,long long y)
{
	return x>y?x:y;
}
int main()
{
	long long s;
	cin>>n>>k;
	s=0;
	//memset(c,0,sizeof(c));
	//memset(lsh,0,sizeof(lsh));
	//memset(lsh_cp,0,sizeof(lsh_cp));
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&lsh[i].data);
		lsh[i].id=i; //��¼�������ԭλ�� 
	}
	sort(lsh+1,lsh+n+1); //�Ȱ���ֵ��С���� 
	long long cnt=1;
	for(long long i=1;i<=n;i++)
	{
		if(i!=1 && lsh[i].data!=lsh[i-1].data) cnt++; //��ɢ��ע��ȥ�� 
		lsh_cp[lsh[i].id]=cnt; //�ٰ���ֵ��С�����˳�����θ���ֵ1~n, �ȱ�֤����Դ�С��ϵ����, �ַ�ֹ��n��������Խ�� 
	}
	//������ɢ�������൱�ڰ�lsh������lsh_cp��,������Դ�С��ϵ����,�������� 
	for(long long i=1;i<=n;i++)
	{
		add(lsh_cp[i],1);
		s=s+i-sum(lsh_cp[i]);
	}
	printf("%lld\n",max(s-k,0));
	return 0;
}
