//ÏßÐÔÉ¸Ä£°å 
#include<iostream>
using namespace std;
long long n,m;
bool notzs[1500000100];
int main()
{
	cin>>n>>m;
	notzs[0]=1;
	notzs[1]=1;
	for(long long i=2;i<=m;i++)
	{
		if(notzs[i]==1) continue;
		for(long long j=i;i*j<=m;j++) notzs[i*j]=1;
	}
	long long l,r,s;
	for(long long i=1;i<=n;i++)
	{
		cin>>l>>r;
		s=0;
		if(!(l>=1 && l<=m && r>=1 && r<=m)){
			cout<<"Crossing the line"<<endl;
			continue;
		}
		for(long long j=l;j<=r;j++) if(notzs[j]==0) s++;
		cout<<s<<endl;
	}
	return 0;
}
