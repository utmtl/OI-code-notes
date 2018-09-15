#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const ull mod1=19260817,mod2=20031029,base=233;
/*
ull hash1(char s[])
{
	ull ans=0,l=strlen(s);
	for(int i=0;i<l;i++)
	{
		ans=(ans*base+(ull)s[i])%mod1;
	}
	return ans;
}
ull hash2(char s[])
{
	ull ans=0,l=strlen(s);
	for(int i=0;i<l;i++)
	{
		ans=(ans*base+(ull)s[i])%mod2;
	}
	return ans;
}
struct node{
	ull x,y;
}a[10010];
bool cmp(const node &x,const node &y)
{
	if(x.x<y.x) return 1;
	return 0;
}
*/
ull a[10010];
ull hash(char s[])
{
	ull ans=0,l=strlen(s);
	for(int i=0;i<l;i++)
	{
		ans=ans*base+(ull)s[i];
	}
	return ans&0x7fffffff;
	//line 43 means:
	//if(ans>=0) return ans;
	//else return -ans;
}
int main()
{
	int n;
	char x[10000];
	cin>>n;
	/*
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i].x=hash1(x);
		a[i].y=hash2(x);
	}
	sort(a+1,a+n+1,cmp);
	int s=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].x!=a[i-1].x || a[i].y!=a[i-1].y) s++;
		//只要两哈希值中有一个不同就字符串不同，双哈希就是防止不同字串哈希值相同 
	}
	*/
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=hash(x);
		//cout<<a[i]<<endl;
	}
	sort(a+1,a+n+1);
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1]) s++;
	}
	cout<<s;
	return 0;
}
