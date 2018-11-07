#include<cstdio>
#include<cstring>
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
int size=3,n,T;
const int mod=1000000007;
struct jz{
	int v[5][5];
	void ql()
		{
			memset(v,0,sizeof(v));
		}//矩阵清零
	void csh()
		{
			ql();
			for(re int i=1;i<=size;++i)
				v[i][i]=1;
		}//赋值为单位矩阵
	jz operator *(const jz &t)const
		{
			jz c;
			c.ql();
			for(re int i=1;i<=size;++i)
				for(re int j=1;j<=size;++j)
					for(re int k=1;k<=size;++k)
						c.v[i][j]=c.v[i][j]%mod+v[i][k]*t.v[k][j]%mod;
			return c;
		}//矩阵乘法
};
jz ksm(jz a,int p)//矩阵快速幂
{
	/*
	  非递归快速幂思想:
	  假设p=11,即二进制1011
	  则p=2^3+2^2+2^0
	  那么a^p转化为a^2^3*a^2^2*a^2^0
	  a^2^x即base,a^2^(x+1)可以很快由a^2^(x)乘a得到
	  只要p的二进值末尾为1, 就乘入ans即可
	*/
	jz ans,base=a;//base一开始为a^2^0即a
	ans.csh();//注意ans要初始化为单位矩阵
	while(p)
	{
		if(p&1) ans=ans*base; //如果p的二进制末尾为1,ans就要乘上a^2^x. 这里别去想什么奇数偶数的, 直接看p的二进制
		base=base*base; //base由a^2^x转为a^2^(x+1)
		p>>=1; //p的末尾已处理完(a^2^x已乘入ans)
	}
	return ans;
}
signed main()
{
	jz st,zy;
	st.ql();
	zy.ql();
	st.v[1][1]=1;st.v[1][2]=1;st.v[1][3]=1;
	//初始矩阵st为|1 1 1|
	zy.v[1][1]=0;zy.v[1][2]=0;zy.v[1][3]=1;
	zy.v[2][1]=1;zy.v[2][2]=0;zy.v[2][3]=0;
	zy.v[3][1]=0;zy.v[3][2]=1;zy.v[3][3]=1;
	/*
	  转移矩阵为
	  |0 0 1|
	  |1 0 0|
	  |0 1 1|
	  f[n]~f[n+1]转移过程:
	  |f[n-2] f[n-1] f[n]| * |0 0 1| = |f[n-1] f[n] f[n-2]+f[n]| =|f[n-1] f[n] f[n+1]|
	                         |1 0 0|
	                         |0 1 1|
	*/
	T=read();
	for(re int i=1;i<=T;++i)
	{
		n=read();
		jz ans=st*ksm(zy,n-1);//转移次数玄学调一下就好.这里st*zy^(n-1)得到[1][1]为答案
		printf("%lld\n",ans.v[1][1]%mod);
	}
	return 0;
}
