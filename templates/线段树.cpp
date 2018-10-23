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
void build(ll p,ll l,ll r) //����. p��ָ��tree�Ľڵ��������е�λ��. 
{
	ll mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	if(l==r){ //Ҷ�ӽ�����a�еĵ���Ԫ��(Ԫ����), ��ֹ�ݹ� 
		t[p].data_max=a[l];
		t[p].data_sum=a[l];
		return;
	}
	build(2*p,l,mid); //����Ӵ�������� 
	build(2*p+1,mid+1,r); //�Ҷ��Ӵ��ұ�����
	//���������Ƚ���ά����, ���Դ�ά�����׽ڵ� 
	t[p].data_max=max(t[2*p].data_max,t[2*p+1].data_max);
	t[p].data_sum=t[2*p].data_sum+t[2*p+1].data_sum;
	//ά�����������ֵ��������������֮��. ʵ����, �κ���������(������������Ϣ֮�Ϳ���)����Ϣ�����Ա�ά�� 
}
void change(ll p,ll i,ll v) //��a[i]�޸�Ϊv. 
{
	ll mid=(t[i].l+t[i].r)/2;
	if(t[i].l==t[i].r){ //���ҵ�����a[i]�Ľڵ� 
		t[i].data_max=v;
		return;
	}
	if(i<=mid) change(p*2,i,v); //i�����������
	else change(p*2+1,i,v); //i�����Ұ����� 
	t[p].data_max=max(t[p*2].data_max,t[p*2+1].data_max);
	t[p].data_sum=t[p*2].data_sum+t[p*2+1].data_sum;
	//�������ϸ������Ƚڵ㱣�����ά������Ϣ 
}
ll ask_max(ll p,ll l,ll r)
{
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=t[p].l && r>=t[p].r) return t[p].data_max;
	ll v=LLONG_MIN; //long long����Сֵ. �����������͵ļ���ֵ������ͷ�ļ�<climits>�� 
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
}//ͬ��, ������� 
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n); //���ڵ������[1,n]��������,����һ�в����Ӹ�(p==1)��ʼ
	printf("%lld\n",ask_sum(1,1,n));
	return 0;
}
