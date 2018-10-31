#include<cstdio>
#include<algorithm>
#include<cmath>
#define db double
#define ll long long
#define re register
using namespace std;
inline ll read()
{
	ll s=0,b=1;
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
ll n;
struct node{
	ll x,y;
}p[210000];
inline db dis(ll t1,ll t2)
{
	return sqrt((p[t1].x-p[t2].x)*(p[t1].x-p[t2].x)+(p[t1].y-p[t2].y)*(p[t1].y-p[t2].y));
}
bool cmpx(const node &t1,const node &t2)
{
	return t1.x<t2.x;
}
bool cmpy(const int &t1,const int &t2)
{
	return p[t1].y<p[t2].y;
}
inline db min(db a,db b)
{
	return a<b?a:b;
}
inline db abs(db a)
{
	return a>0?a:-a;
}
int ls[210000];
db work(ll l,ll r) 
{
	if(l==r) return (db)1e20; //显然一个点不能和他自身配对
	if(l+1==r) return dis(l,r); //若区间内只有2个点,直接返回距离
	ll mid=(l+r)>>1;
	db ans=min(work(l,mid),work(mid+1,r)); //利用分治的思想, 把求整个区间的最近点对转化为求左右两半的最近点对
	//注意!!![l,r]的最近点对不等于min([l,mid]最近点对,[mid+1,r]最近点对), 还有两边的点分别配对的情况没考虑
	//但有了一个最短距离ans后, 两边距离大于ans的点就不用考虑了, 降低了复杂度
	int cnt=0;
	for(re ll i=l;i<=r;i++)
		if(abs(p[mid].x-p[i].x)<=ans) ls[++cnt]=i; //距离有可能小于ans(x轴距离必须小于ans)的点对纳入考虑范围
	sort(ls+1,ls+cnt+1,cmpy); //距离可能小于ans的点按纵坐标排序
	for(re ll i=1;i<=cnt;i++)
	{
		for(re ll j=i+1;j<=cnt;j++)
		{
			if(p[ls[j]].y-p[ls[i]].y<ans)
			{
				if(dis(ls[j],ls[i])<ans) ans=dis(ls[j],ls[i]);
			}
			else break; //枚举这些点的配对情况. 由于之前排了序, 距离是单调增大的, 距离一旦大于ans就可以break
		}
	}
	return ans;
}
int main()
{
	n=read();
	for(re int i=1;i<=n;i++)
	{
		p[i].x=read();
		p[i].y=read();
	}
	sort(p+1,p+n+1,cmpx); //为了便于分治(二分),先以x为关键字将点排序
	printf("%0.4lf\n",work(1,n));
	return 0;
}
