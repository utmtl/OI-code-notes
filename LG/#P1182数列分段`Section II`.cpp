/*����ģ���� 
����Ҫ��ÿ�κ͵����ֵ����Сֵ����ֻ������l:max{a[i]} ~ r:a[1]+a[2]+a[3]...+a[n]֮��
ֱ�Ӷ��ֲ��ҿ��ܵ���Сֵ
���ͨ��chk��������������ôС���Ͳ���������䣨��С��
������������ұ����䣨����
*/
#include<iostream>
using namespace std;
long long n,m,a[100100],l,r,mid,ans;
bool chk(long long x) //����Ƿ�������ͨ���ֳ�С�ڵ���m��ʹ�͵�maxС��x 
{
	long long s=1,t=0;
	for(int i=1;i<=n;i++)
	{
		if(t+a[i]<=x) t+=a[i];
		else t=a[i],s++;
	}
	if(s<=m) return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r+=a[i];
		if(a[i]>l) l=a[i];
	}
	while(l<=r){
		mid=(l+r)/2;
		if(chk(mid)==true) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
