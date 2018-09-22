/*
STL _vector动态数组使用模板
本来类似于树的孩子表示法，在每个node中定义next[50]数组，结果炸空间 
实际上不一定每个node都有50个孩子
所以引入动态数组 

------------------

v.push_back(t)
在容器的最后加入一个值为t的数据，容器的size变大。
另外list有push_front()函数，在前端插入，后面的元素下标依次增大。
v.size()
返回容器中数据的个数，size返回对应vector类定义的size_type的值。v.resize(2*v.size)
或v.resize(2*v.size, 99) 将v的容量翻倍(并把新元素的值初始化为99)
v.empty()
推断vector是否为空
v[n]
返回v中位置为n的元素
v.insert(pointer,number, content)
向v中pointer指向的位置插入number个content的内容。
还有v. insert(pointer, content)，v.insert(pointer,a[2],a[4])将a[2]到a[4]三个元素插入。
v.pop_back()
删除容器的末元素，并不返回该元素。
v.erase(pointer1,pointer2)
删除pointer1到pointer2中间（包含pointer1所指）的元素。
vector中删除一个元素后，此位置以后的元素都须要往前移动一个位置，尽管当前迭代器位置没有自己主动加1，
可是因为兴许元素的顺次前移，也就相当于迭代器的自己主动指向下一个位置一样。
v1==v2
推断v1与v2是否相等。
！=、<、<=、>、>=
保持这些操作符惯有含义。
v.clear()
删除容器中的全部元素。

---------------

*/
#include<iostream>
#include<vector>
using namespace std;
struct node{
	int chu,ru;
	vector<int> next;
}a[200100];
int n,m,mem[200100];
long long s;
int dfs(int x)
{
	int t=0;
	if(a[x].chu==0) return 1;
	if(mem[x]!=0) return mem[x];
	for(int i=1;i<=a[x].chu;i++)
	{
		t+=dfs(a[x].next[i]);
	}
	mem[x]=t;
	return t;
}
int main()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].next.push_back(0);
	}
	//注意push_back()默认从0下标开始，要先把所有next[0]占掉 
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].chu++;
		a[x].next.push_back(y);
		a[y].ru++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!(a[i].ru==0 && a[i].chu!=0)) continue;
		s+=dfs(i);
	}
	cout<<s;
	return 0;
}
