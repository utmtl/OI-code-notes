//这篇不错: http://www.cnblogs.com/chinhhh/p/7965433.html
#include<cstdio>
#define in inline
#define re register
#define ll long long
#define lc p<<1
#define rc (p<<1)+1
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-') b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return b?-s:s;
}
const int N=100001;
int n,m,root,yyb;
struct edge{
	int t,nxt;
}e[N*2];
int cnt,head[N];
int w[N],id[N],wid[N],f[N],d[N],subt[N],son[N],top[N];
//w节点原始权值;f[x]x的父亲;d[x]x节点的深度;subt[x]以x为根的子树的节点数;son[x]x的重儿子;top[x]x节点所在的链的链顶
//id[x]x节点树剖后的新编号;wid按新编号存放的节点权值;(树->链,方便在线段树上处理)
in void add(int f,int t)
{
	++cnt;
	e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;
	++cnt;
	e[cnt].t=f,e[cnt].nxt=head[t],head[t]=cnt;
}
//以下是线段树板子
struct SegmentTree{
	int l,r,sum,add;
}t[N*4];
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r) {t[p].sum=wid[l];return;}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[p].sum=(t[lc].sum+t[rc].sum)%yyb;
}
in void spread(int p)
{
	if(!t[p].add) return;
	t[lc].add+=t[p].add,t[rc].add+=t[p].add;
	t[lc].sum+=t[p].add*(t[lc].r-t[lc].l+1);
    //t[lc,rc].add原先的值已经加入t[lc,rc].sum中, 这里应用t[p].add来乘而非t[lc,rc].add
	t[rc].sum+=t[p].add*(t[rc].r-t[rc].l+1);
	t[p].add=0;
	t[lc].sum%=yyb,t[rc].sum%=yyb;
}
int ask(int p,int l,int r)
{
	if(l<=t[p].l && t[p].r<=r) return t[p].sum%yyb;
	spread(p);
	int mid=(t[p].l+t[p].r)>>1,ans=0;//不是 (l+r)>>1 !!!又错这里!!!
	if(l<=mid) ans+=ask(lc,l,r);
	if(r>mid) ans+=ask(rc,l,r);
	return ans%yyb;
}
void update(int p,int l,int r,int a)
{
	if(l<=t[p].l && t[p].r<=r){t[p].add+=a,t[p].sum+=a*(t[p].r-t[p].l+1),t[p].sum%=yyb;return;}
	//同line54, 这里是a*而不是t[p].add*
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;//不是 (l+r)>>1 !!!又错这里!!!
	if(l<=mid) update(lc,l,r,a);
	if(r>mid) update(rc,l,r,a);
	t[p].sum=(t[lc].sum+t[rc].sum)%yyb;//你TM修改了不更新
}
//以上是线段树板子
void dfs1(int now,int fa)
{
	//第一次dfs: 预处理深度, 父亲, 子树大小, 重儿子
	d[now]=d[fa]+1,f[now]=fa,subt[now]=1;
	int maxson=0;
	for(re int i=head[now];i;i=e[i].nxt)
	{
		if(e[i].t==fa) continue;
		dfs1(e[i].t,now);
		subt[now]+=subt[e[i].t];
		if(subt[e[i].t]>maxson) maxson=subt[e[i].t],son[now]=e[i].t;
	}
}
void dfs2(int now,int topfa)
{
	//第二次dfs: 把树编号, 剖分成一条条链, 处理出top[]
	++cnt;
	id[now]=cnt,wid[cnt]=w[now],top[now]=topfa;
	if(!son[now]) return;//叶子节点
	dfs2(son[now],topfa);
    //重链剖分: 先递归重链, 所以每条重链的新编号是连续的
	//又因为是dfs, 所以每个子树的新编号也是连续的
	//这样就转化为线性区间了
	for(re int i=head[now];i;i=e[i].nxt)
		if(e[i].t!=f[now] && e[i].t!=son[now]) dfs2(e[i].t,e[i].t);//每个轻儿子都有一条以它为topfa的链 
}
in int aksr(int x,int y)
{
	//求x-y最短路径经过的点权之和: 设所在链顶端深度深的点为x
    //ans加上x到top[x]这段区间的点权和, 再x跳到fa[top[x]]
	//重复, 直至x,y在一条链上(top[x]==top[y]), 此时ans加上x-y这段线性连续区间和即可
	int ans=0;
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]]) x^=y,y^=x,x^=y;
		ans+=ask(1,id[top[x]],id[x]);
		ans%=yyb;
		x=f[top[x]];
	}
	if(d[x]<d[y]) x^=y,y^=x,x^=y;
	ans+=ask(1,id[y],id[x]);
	return ans%yyb;
}
in void updr(int x,int y,int a)
{
	//x-y最短路径每个点+=a: 同上
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]]) x^=y,y^=x,x^=y;
		update(1,id[top[x]],id[x],a%yyb);
		x=f[top[x]];
	}
	if(d[x]<d[y]) x^=y,y^=x,x^=y;
	update(1,id[y],id[x],a%yyb);
}
//对于x为根的整个子树的处理: x子树节点新编号为id[x]~id[x]+subt[x]-1, 处理这段线性连续区间即可
in int asksub(int x) {return ask(1,id[x],id[x]+subt[x]-1);}
in void updsub(int x,int a) {update(1,id[x],id[x]+subt[x]-1,a);}
signed main()
{
	n=read(),m=read(),root=read(),yyb=read();
	for(re int i=1;i<=n;++i) w[i]=read();
	for(re int i=1;i<=n-1;++i){int u=read(),v=read();add(u,v);}
	dfs1(root,0);
	cnt=0;
	dfs2(root,root);
	build(1,1,n);//树剖后按wid建线段树,树->链
	for(re int i=1;i<=m;++i)
	{
		int x,y,z;
		x=read();
		if(x==1){x=read(),y=read(),z=read();updr(x,y,z);}
		else if(x==2){x=read(),y=read();printf("%d\n",aksr(x,y));}
		else if(x==3){x=read(),y=read();updsub(x,y);}
		else{x=read();printf("%d\n",asksub(x));}
	}
	return 0;
}
