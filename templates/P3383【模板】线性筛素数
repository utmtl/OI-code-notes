#include<iostream>
using namespace std;
long long n,m;
bool notzs[1500000100];
int main()
{
	cin>>n>>m;
	notzs[0]=1;
	notzs[1]=1;
	for(long long i=2;i<=n;i++)
	{
		if(notzs[i]==1) continue;
		for(long long j=i;i*j<=n;j++) notzs[i*j]=1;
	}
	long long x;
	for(long long i=1;i<=m;i++)
	{
		cin>>x;
		if(notzs[x]==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
