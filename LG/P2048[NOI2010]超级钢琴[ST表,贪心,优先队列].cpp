#include<cstdio>
#include<queue>
#define re register
#define in inline
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
int n,k,L,R;
int mx[500010][31],sum[500010],log[500010];
in int min(int x,int y)
{
	return x<y?x:y;
}
in void init()
{//保存sum[l~r]最大值位置的ST表
    for(re int i=1;i<=n;++i) mx[i][0]=i;
    for(re int j=1;j<31;++j)
        for(re int i=1;i+(1<<j)-1<=n;++i)
			mx[i][j]=sum[mx[i][j-1]]>sum[mx[i+(1<<(j-1))][j-1]]?mx[i][j-1]:mx[i+(1<<(j-1))][j-1];
	int cnt=1;
    log[1]=0;
    for(re int i=2;i<=n;++i)
    {
        if((1<<(cnt+1))==i) ++cnt;
        log[i]=cnt;
    }
}
in int ask(int l,int r)
{
	int t=log[r-l+1];
	if(sum[mx[l][t]]>sum[mx[r-(1<<t)+1][t]]) return mx[l][t];
	else return mx[r-(1<<t)+1][t];
}//求sum_l~r最大值位置
struct node{
	int o,l,r,pos;
	bool operator < (const node &t)const
		{
			return sum[pos]-sum[o-1]<sum[t.pos]-sum[t.o-1];
		}
};//每个三元组表示左端点为o, 右端点在l~r内的若干区间中的最大权值, t为sum_l~r最大值位置
//(o,l,r)=max(sum[l~r]-sum[o-1]), sum[o-1]固定, 所以在l~r内找到最大的sum[pos]即可保证[o,pos]区间最大值为最大
priority_queue<node> q;
in void make(int o,int l,int r)
{
	node x;
	x.o=o;
	x.l=l;
	x.r=r;
	x.pos=ask(l,r);
	q.push(x);
}
int main()
{
    n=read();
    k=read();
    L=read();
	R=read();
	for(re int i=1;i<=n;++i) sum[i]=sum[i-1]+read();
	init();//预处理RMQ
    for(re int i=1;L+i-1<=n;++i) make(i,i+L-1,min(i+R-1,n));//枚举区间起点, 把所有最大值放入大根堆
	long long ans=0;
	for(re int i=1;i<=k;++i)
	{
//我们不仅要求最大的那个区间, 还要求第2~第k大的区间,
//所以在我们从堆中取出当前最大值(o,l,r)时, 还要把(o,l,r)包括的所有区间(除区间[o,pos]外)的其他可能次优解重新放回堆中(贪心)
//(o,l,pos-1)和(o,pos+1,r)就包括了除区间[o,pos]外以o为起点的所有区间情况的最大值
		node x=q.top();
		q.pop();
		ans+=sum[x.pos]-sum[x.o-1];
		if(x.l<=x.pos-1) make(x.o,x.l,x.pos-1);
		if(x.pos+1<=x.r) make(x.o,x.pos+1,x.r);
	}
	printf("%lld\n",ans);
    return 0;
}
