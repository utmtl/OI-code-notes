#include<cstdio>
#define re register
#define in inline
#define int long long
inline int read()
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
}//快读是不可能出锅的
int n,k;
struct node{
	int p,t;
}task[11000];
int f[11000],b[11000];
int max(int x,int y)
{
	return x>y?x:y;
}
signed main()
{
	n=read();
	k=read();
	for(re int i=1;i<=k;++i)
	{
		task[i].p=read();
		task[i].t=read();
		++b[task[i].p];
	}
	/*
	  f[i]表示时间i~n内的最大休息时间(问什么设什么)
	  已知f[n+1]=0, 求f[1]
	  转移方程:(无任务时直接从下一秒+1转移过来, 有任务则只能从这个任务完成之后的时刻转移)
	  |f[x]=f[x+1]+1 (x时刻无任务)
	  |f[x]=max(f[x],f[x+task[j].t]) (x时刻有任务, 所有task[j].p==x)
	  明显要逆推, f[x]是从x时刻之后的状态转移来的
	*/
	for(re int i=n;i>=1;--i)
	{
		if(!b[i]) f[i]=f[i+1]+1;
		else
		{
			for(re int j=1;j<=k;++j)
			{
				if(task[j].p==i)
					f[i]=max(f[i+task[j].t],f[i]);
			}
		}
	}
	printf("%lld\n",f[1]);
	return 0;
}
