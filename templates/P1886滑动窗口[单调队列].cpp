#include<cstdio>
#define re register
#define in inline
#define int long long
in int read()
{
	int s=0,b=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=-1;
	}while(ch<'0' || ch>'9');
	while(ch>='0' && ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return b*s;
}
int n,k;
struct queue{
	int w,num;
}q[1000010];
int h,t,a[1000010];
signed main()
{
	n=read();
	k=read();
	for(re int i=1;i<=n;++i)
		a[i]=read();
	h=1;
	t=1;//注意h指向队首, t指向最后一个元素
	for(re int i=1;i<=n;++i)
	{
		while(h<=t && q[t].w>=a[i]) --t; //维护单调性: 不小于a[i]的出队
		q[++t].w=a[i];
		q[t].num=i; //a[i]入队
		while(q[h].num<=i-k) ++h; //过期的出队
		if(i>=k) printf("%lld ",q[h].w);
	}
	printf("\n");
	h=1;
	t=1;
	for(re int i=1;i<=n;++i)
	{
		while(h<=t && q[t].w<=a[i]) --t;
		q[++t].w=a[i];
		q[t].num=i;
		while(q[h].num<=i-k) ++h;
		if(i>=k) printf("%lld ",q[h].w);
	}
	printf("\n");
	return 0;
}
