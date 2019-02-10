/*
f[i]为在[1,i]中选数的最大值.
显然f[i]=max(f[j-1]+sum[j~i]),i-k<=j<=i(j为断点)
即f[i]=max(f[j-1]+sum[i]-sum[j-1])
      =max(f[j-1]-sum[j-1])+sum[i]
满足决策单调性, 所以用一个优先队列维护 max(f[j-1]-sum[j-1]),i-k<=j<=i 即可
*/
#include<cstdio>
#include<queue>
#define re register
#define in inline
#define int long long
using namespace std;
in int read()
{
	int s=0,b=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=1;
	}while(ch<'0' || ch>'9');
	while(ch>='0' && ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return b?-s:s;
}
int n,k,e[100001],f[100001],sum[100001];
struct node{
	int data,pos;
	bool operator<(const node &t)const
		{
			return data<t.data;//优先队列默认为大根堆, 不用重载为>
		}
};
priority_queue<node> q;
signed main()
{
	n=read();
	k=read();
	for(re int i=1;i<=n;++i) e[i]=read(),sum[i]=sum[i-1]+e[i];
	node t;
	t.pos=0,t.data=0;
	q.push(t);//为了正确求出f[1]
	for(re int i=1;i<=n;++i)
	{
		t.pos=i;
		t.data=f[i-1]-sum[i];
		q.push(t);
		while(!q.empty() && q.top().pos<i-k) q.pop();
		f[i]=q.top().data+sum[i];
	}
	printf("%lld\n",f[n]);
	return 0;
}
