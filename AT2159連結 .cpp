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
	//���Ȱ����������ò��鼯����Ϊһ������ͨ�飬
	//Ҫ ���ͨ����·��ͨ��ͨ����·��ͨ�ĳ����� ��ת��Ϊ�� ���fg��ft�Ľ���Ԫ���� 
	//����ֻ����mapͳ��ÿ�������е����������
	for(int i=1;i<=n;i++)
	{
		s[{fg[i],ft[i]}]++;
		//���������֮������߹�·�����������·������ǿ϶�����ͬһ����������ôfg[i]��ft[i]�Ľ���Ԫ����+1 
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",s[{fg[i],ft[i]}]);
	}
	return 0;
}
