/*二分模板题 
由于要求每段和的最大值的最小值，答案只可能在l:max{a[i]} ~ r:a[1]+a[2]+a[3]...+a[n]之间
直接二分查找可能的最小值
如果通过chk检查出可以做到这么小，就查找左边区间（更小）
做不到则查找右边区间（更大）
*/
#include<iostream>
using namespace std;
long long n,m,a[100100],l,r,mid,ans;
bool chk(long long x) //检查是否能做到通过分成小于等于m段使和的max小于x 
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
