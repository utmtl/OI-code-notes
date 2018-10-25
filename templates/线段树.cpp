#include<cstdio>
#include<climits>
#define ll long long
const ll n_max=100100;
ll a[n_max],n,m;
struct SegmentTree{
	ll l,r,max,sum;
	ll add; //延迟标记: add为其子节点要加却还未加的值(该节点本身已被修改)
}t[4*n_max];
inline ll max(ll x,ll y)
{
	return x>y?x:y;
}
void build(ll p,ll l,ll r) //建树. p是指向tree的节点在数组中的位置. 
{
	ll mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	if(l==r){ //叶子结点代表a中的单个元素(元区间), 终止递归 
		t[p].max=a[l];
		t[p].sum=a[l];
		return;
	}
	build(2*p,l,mid); //左儿子存左边区间 
	build(2*p+1,mid+1,r); //右儿子存右边区间
	//左右子树先建立维护好, 再以此维护父亲节点 
	t[p].max=max(t[2*p].max,t[2*p+1].max);
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
	//维护了区间最大值和区间内所有数之和. 实际上, 任何满足结合律(即两个区间信息之和可算)的信息都可以被维护 
}
inline void spread(ll p) //标记下传 函数. 改变区间, 查询区间时就调用此函数以下传修改的值
{
	if(t[p].add!=0)
	{
		t[p*2].sum=t[p*2].sum+t[p].add*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].sum=t[p*2+1].sum+t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
		//这个区间每个数+v,则整个区间+v*(t[p].r-t[p].l+1)
		t[p*2].add+=t[p].add;
		t[p*2+1].add+=t[p].add;
		t[p].add=0;
	}
}
void change(ll p,ll i,ll v) //把a[i]修改为v. 
{
	ll mid=(t[i].l+t[i].r)/2;
	if(t[i].l==t[i].r){ //若找到代表a[i]的节点 
		t[i].max=v;
		return;
	}
	spread(p);
	if(i<=mid) change(p*2,i,v); //i属于左半区间
	else change(p*2+1,i,v); //i属于右半区间 
	t[p].max=max(t[p*2].max,t[p*2+1].max);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	//从下往上更新祖先节点保存的所维护的信息 
}
void add(ll p,ll l,ll r,ll v)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r){
		t[p].sum=t[p].sum+v*(t[p].r-t[p].l+1); //这个区间每个数+v,则整个区间+v*(t[p].r-t[p].l+1)
		t[p].add+=v; //打标记,代表此节点的子节点等待被更新
		return;
	}
	spread(p);
	if(l<=mid) add(p*2,l,r,v);
	if(r>mid) add(p*2+1,l,r,v);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
ll ask_max(ll p,ll l,ll r)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r) return t[p].max;
    //若此节点代表的区间包含于询问的区间中,直接返回这个区间的信息作为_候选信息_
	spread(p);
	ll v=LLONG_MIN; //long long的最小值. 各种数据类型的极限值包含于头文件<climits>中 
	if(l<=mid) v=max(v,ask_max(p*2,l,r)); //只递归(将节点代表的区间缩小到)左子树(左半边区间)
	if(r>mid) v=max(v,ask_max(p*2+1,l,r)); //只递归(将节点代表的区间缩小到)右子树(右半边区间)
	return v;
}
ll ask_sum(ll p,ll l,ll r)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r) return t[p].sum;
	spread(p);
	ll v=0;
	if(l<=mid) v=v+ask_sum(p*2,l,r);
	if(r>mid) v=v+ask_sum(p*2+1,l,r);
	return v;
}//同理, 区间求和 
int main()
{
	ll x,y,k;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n); //根节点代表了[1,n]整个区间,所以一切操作从根(p==1)开始
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		if(x==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			add(1,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask_sum(1,x,y));
		}
	}
	return 0;
}
