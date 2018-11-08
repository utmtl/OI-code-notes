#include<cstdio>
#include<iostream>
#define ll long long
#define re register
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
ll t;
ll f[31000],dis[31000],size[31000]; //dis[x]为x到其根的距离(即边权)
ll find(ll x)
{
	if(x!=f[x]){
		ll root=find(f[x]); //注意要先find维护好排在前面的战舰,才能把这个x到根的dis算出来
		dis[x]+=dis[f[x]];
		f[x]=root; //路径压缩
	}
	return f[x];
}
void un(ll r1,ll r2)
{
	r1=find(r1);
	r2=find(r2);
	if(r1!=r2){
		f[r1]=r2; //注意r2在r1前面
		dis[r1]=size[r2]; //新加的r1到r2的边权值就是原r2队列的战舰个数
		size[r2]+=size[r1]; //r2开头的战舰队列战舰数增加
	}
}
ll abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	ll i,j;
	char ch;
	t=read();
	for(re int i=1;i<=30000;i++) f[i]=i,size[i]=1;
	for(re int k=1;k<=t;k++)
	{
		std::cin>>ch; //getchar()玄学WA
		i=read();
		j=read();
		if(ch=='M') un(i,j);
		if(ch=='C')
		{
			int x=find(i);
			int y=find(j);
			if(x!=y) printf("-1\n");
			else printf("%lld\n",abs(dis[i]-dis[j])-1); //i到根(此列最开头的战舰)和j到根的距离之差-1为i, j相隔战舰数
		}
	}
	return 0;
}
