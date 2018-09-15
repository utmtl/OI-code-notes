#include<iostream>
using namespace std;
int t,m;
int w[1001],c[1001],f[1001];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>c[i]; //time xx
	}
	for(int i=1;i<=m;i++)
	{
		for(int v=t;v>=w[i];v--)
		{
			f[v]=max(f[v],f[v-w[i]]+c[i]);
		}
	}
	cout<<f[t];
	return 0;
}
