#include<cstdio>
#define ll long long
#define re register
inline ll read()
{
	re ll s=0,b=1;
	re char ch;
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
double a[10000][10000];
int main()
{
	n=read();
	for(re ll i=1;i<=n;i++)
		for(re ll j=1;j<=n+1;j++)
			a[i][j]=(double)(read());
	for(re ll i=1;i<=n;i++)
	{
		if(a[i][i]==0){//对角线系数必须不为0
			ll x=-1;
			for(re ll j=i+1;j<=n;j++)
			{
				if(a[j][i]!=0){
					x=j;
					break;
				}
			}//找到一个带有这个元的式子
			if(x==-1)
			{
				printf("No Solution\n");
				return 0;
			}//根本没有这个元
			for(re ll j=1;j<=n+1;j++)
			{
				ll t=a[i][j];
				a[i][j]=a[x][j];
				a[x][j]=t;
			}//两行交换
		}
	    for(re ll j=n+1;j>=i;j--)//注意,不能从a[i][i]开始从左往右除!!!a[i][i]除后变成1,而后面所有数都要除a[i][i]. 只能从右往左除. 由于i之前的系数已经全部消为0,只要循环到i即可
		{
			a[i][j]/=a[i][i];
	  	}//此行主元的系数化为一
		for(re ll j=1;j<=n;j++)
		{
			if(i==j) continue; //用这一行对别的行做加减消元
			double x=a[j][i]/a[i][i];
			for(re ll k=1;k<=n+1;k++)
			{
				a[j][k]-=x*a[i][k]; //第j行减第i行同乘x,使第i列(除主元a[i][i])全部消为0
			}
	   	}
	}
	for(re ll i=1;i<=n;i++){
		if(a[i][i]!=1){
			printf("No Solution\n");
			return 0;
		}
	}
	for(re ll i=1;i<=n;i++) printf("%0.2lf\n",a[i][n+1]);
	return 0;
}
