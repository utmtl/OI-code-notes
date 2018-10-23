#include<cstdio>
#include<climits>
#define ll long long
const ll n_max=100100;
ll a[n_max],n,m;
struct SegmentTree{
	ll l,r,data_max,data_sum;
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
		t[p].data_max=a[l];
		t[p].data_sum=a[l];
		return;
	}
	build(2*p,l,mid); //左儿子存左边区间 
	build(2*p+1,mid+1,r); //右儿子存右边区间
	//左右子树先建立维护好, 再以此维护父亲节点 
	t[p].data_max=max(t[2*p].data_max,t[2*p+1].data_max);
	t[p].data_sum=t[2*p].data_sum+t[2*p+1].data_sum;
	//维护了区间最大值和区间内所有数之和. 实际上, 任何满足结合律(即两个区间信息之和可算)的信息都可以被维护 
}
void change(ll p,ll i,ll v) //把a[i]修改为v. 
{
	ll mid=(t[i].l+t[i].r)/2;
	if(t[i].l==t[i].r){ //若找到代表a[i]的节点 
		t[i].data_max=v;
		return;
	}
	if(i<=mid) change(p*2,i,v); //i属于左半区间
	else change(p*2+1,i,v); //i属于右半区间 
	t[p].data_max=max(t[p*2].data_max,t[p*2+1].data_max);
	t[p].data_sum=t[p*2].data_sum+t[p*2+1].data_sum;
	//从下往上更新祖先节点保存的所维护的信息 
}
ll ask_max(ll p,ll l,ll r)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r) return t[p].data_max;
	ll v=LLONG_MIN; //long long的最小值. 各种数据类型的极限值包含于头文件<climits>中 
	if(l<=mid) v=max(v,ask_max(p*2,l,r));
	if(r>mid) v=max(v,ask_max(p*2+1,l,r));
	return v;
}
ll ask_sum(ll p,ll l,ll r)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r) return t[p].data_sum;
	ll v=0;
	if(l<=mid) v=v+ask_sum(p*2,l,r);
	if(r>mid) v=v+ask_sum(p*2+1,l,r);
	return v;
}//同理, 区间求和 
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n); //根节点代表了[1,n]整个区间,所以一切操作从根(p==1)开始
	printf("%lld\n",ask_sum(1,1,n));
	return 0;
}
