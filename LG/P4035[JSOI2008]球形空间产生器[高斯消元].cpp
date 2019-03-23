#include<cstdio>
#define re register
#define int long long
#define db double
#define in inline
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int n;
double a[20][20],b[20][20];
signed main()
{
	n=read();
	for(re int i=1;i<=n+1;++i)
		for(re int j=1;j<=n;++j)
			scanf("%lf",&a[i][j]);
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			b[i][j]=2*(a[i][j]-a[i+1][j]),b[i][n+1]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
	/*
	原方程组a：
	|(x-a1_x)^2+(y-a1_y)^2=R^2
	|(x-a2_x)^2+(y-a2_y)^2=R^2
	|(x-a3_x)^2+(y-a3_y)^2=R^2
	相邻两式相减得b：
	|2*(a1_x-a2_x)*x+2*(a1_y-a2_y)*y=a1_x^2-a2_x^2+a1_y^2-a2_y^2
	|2*(a2_x-a3_x)*x+2*(a2_y-a3_y)*y=a2_x^2-a3_x^2+a2_y^2-a3_y^2
	高斯消元解b即可 
	*/
	for(re int i=1;i<=n;++i)
	{
		for(re int j=i;j<=n;++j)
		{
			if(b[j][i]!=0.0){
				for(re int k=1;k<=n+1;++k){db t=b[j][k];b[j][k]=b[i][k],b[i][k]=t;}
				break;
			}
		}
		for(re int j=1;j<=n;++j)
		{
			if(i==j) continue;
			db t=b[j][i]/b[i][i];
			for(re int k=1;k<=n+1;++k) b[j][k]-=b[i][k]*t;
		}
	}
	for(re int i=1;i<=n;++i) printf("%.3lf ",b[i][n+1]/b[i][i]);
	return 0;
}
