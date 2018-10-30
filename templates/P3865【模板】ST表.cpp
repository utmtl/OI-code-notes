#include<cstdio>
#define re register
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
}
int n,m,max[110000][31];
//max[i][j]表示区间[i,i+2^j-1]的最大值, 即从i开始长度为2^j区间的最大值
int k[110000];//k[i]=(int)log_2(i);
int main()
{
	n=read();
	m=read();
	int cnt=1;
	k[1]=0;
	for(re int i=2;i<=n;i++)
	{
		if((1<<(cnt+1))==i) cnt++;
		k[i]=cnt;
		//printf("%d ",k[i]);
	}//预处理出log_2(1~n)的值;
	for(re int i=1;i<=n;i++) max[i][0]=read(); //显然,元区间[i,i]的最值即原数本身
	for(re int j=1;j<31;j++)
	{
		for(re int i=1;i+(1<<j)-1<=n;i++) //注意整个区间[i,i+2^j-1]都不能越界
		{
			max[i][j]=max[i][j-1]>max[i+(1<<(j-1))][j-1]?max[i][j-1]:max[i+(1<<(j-1))][j-1];
			//max[i][j]=max( max[i][j-1] , max[i+(1<<(j-1))][j-1] );
			//显然,区间 [i,i+2^j-1]的最值为 其左半边[i,i+2^(j-1)-1]最值 与 其右半边[i+2^(j-1),i+2^j-1]最值 中的最大值
		}
	}
	int l,r;
	for(re int i=1;i<=m;i++)
	{
		l=read();
		r=read();
		int t=k[r-l+1]; //找出一个整数t使得 2^t < 区间长度 <= 2^(t+1)
		printf("%d\n",max[l][t]>max[r-(1<<t)+1][t]?max[l][t]:max[r-(1<<t)+1][t]);
		//[l,r]的max: max( max[l][t] , max[r-(2^t+1)][t])
		//根据整数t的性质可知 : 以l开头的2^t个数 和 以r结尾的2^t个数 这两段一定覆盖了区间[l,r], 取max即可
	}
	return 0;
}
