#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#define re register
#define in inline
using namespace std;
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
const int N=50001;
struct q_a{
	int l,r,num;
	int ansA,ansB;
}q[N];
int c[N],kuai[N],unit,n,m,sum[N],ans;//ans维护sum平方和
bool cmp1(const q_a &x,const q_a &y)
{
	return kuai[x.l]==kuai[y.l]?x.r<y.r:x.l<y.l;
}
bool cmp2(const q_a &x,const q_a &y)
{
	return x.num<y.num;
}
in int gcd(int a,int b)
{
	while(b^=a^=b^=a%=b);
	return a;
}
in void f(int i,int add)
{
	ans-=sum[c[i]]*sum[c[i]];
	sum[c[i]]+=add;
    ans+=sum[c[i]]*sum[c[i]];
}//转移sum和分子
signed main()
{
	n=read();
	m=read();
	unit=sqrt(n);
	for(re int i=1;i<=n;++i) c[i]=read(),kuai[i]=i/unit+1;
	for(re int i=1;i<=m;++i) q[i].l=read(),q[i].r=read(),q[i].num=i;
	sort(q+1,q+m+1,cmp1);
	int l=1,r=0;
	for(re int i=1;i<=m;++i)
	{
		while(l<q[i].l) f(l,-1),++l;
		while(l>q[i].l) f(l-1,1),--l;
		while(r<q[i].r) f(r+1,1),++r;
		while(r>q[i].r) f(r,-1),--r;
		if(q[i].l==q[i].r) q[i].ansA=0,q[i].ansB=1;
		else{
			q[i].ansA=ans-(q[i].r-q[i].l+1);
			q[i].ansB=(q[i].r-q[i].l+1)*(q[i].r-q[i].l);
			int t=gcd(q[i].ansA,q[i].ansB);
			q[i].ansA/=t;
			q[i].ansB/=t;
		}
	}
	sort(q+1,q+m+1,cmp2);
	for(re int i=1;i<=m;++i) printf("%lld/%lld\n",q[i].ansA,q[i].ansB);
	return 0;
}
