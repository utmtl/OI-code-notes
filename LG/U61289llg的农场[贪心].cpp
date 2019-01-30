//详见2019寒假集训1.30solution
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define re register
#define in inline
#define db double
#define int long long
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
		s=(s<<3)+(s<<1)+(ch^'0');
		ch=getchar();
	}
	return b?-s:s;
}
int n,r,c;
struct node{
    db l,r;
	bool operator<(const node &t)const
		{
			return l<t.l;
		}
}a[50001];
signed main()
{
	while(1)
	{
		n=read();
		r=read();
		c=read();
		if(!n && !r && !c) break;
		int flag=0,x,y;
		for(re int i=1;i<=n;++i)
		{
			x=read();
			y=read();
			if(y>r) flag=1;
		    db t=sqrt(r*r-y*y);
			a[i].l=(db)x-t;
			a[i].r=(db)x+t;
      //平面问题转化为一维区间染色问题
		}
		if(flag) {printf("-1\n");continue;}
		std::sort(a+1,a+n+1);
		db nowr=a[1].r;
		int ans=1;
		for(re int i=2;i<=n;++i)
		{
			if(a[i].l>nowr) ++ans,nowr=a[i].r;
			else nowr=a[i].r<nowr?a[i].r:nowr;//nowr=min(nowr,a[i].r);
		}
		printf("%lld\n",ans>c?-1:ans);
	}
	return 0;
}
