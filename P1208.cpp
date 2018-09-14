#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int p,a,x;
}a[5001];
bool cmp(const node &x,const node &y)
{
	if(x.x<y.x) return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].p>>a[i].a;
		a[i].x=a[i].p/a[i].a;
	}
	sort(a+1,a+m+1,cmp);
	int ans=0,s=0,i=1;
	while(s<n)
	{
		ans+=a[i].p*a[i].a;
		s+=a[i].a;
		i++;
	}
	cout<<ans;
	return 0;
}
/*
100 5
5 20 0.25
9 40 0.225
3 10 0.3
8 80 0.1
6 30 0.2
*/