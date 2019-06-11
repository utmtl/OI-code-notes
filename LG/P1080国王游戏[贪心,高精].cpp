#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
#define in inline
using namespace std;
const int mxl=5000;
in int read()
{
    int s(0),b(0);char ch;
    do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    if(b) return -s;
    return s;
}
struct i128{
	int d[mxl],l;
	i128(char a[])
		{
			memset(d,0,sizeof(d));
			l=strlen(a);
			for(re int i=0;i<l;++i) d[i+1]=a[l-i-1]-48;
		}
	i128()
		{
			memset(d,0,sizeof(d));
			l=1;
		}
	void output()
		{
			for(re int i=l;i>=1;--i) putchar(d[i]+48);
			putchar('\n');
		}
	i128 operator*(const i128 &t)
		{
			i128 s;
			re int x,i,j;
			for(i=1;i<=l;++i)
			{
				x=0;
				for(j=1;j<=t.l;++j)
					s.d[i+j-1]+=d[i]*t.d[j]+x,x=(s.d[i+j-1])/10,s.d[i+j-1]%=10;//注意是+=不是=
				s.d[i+j-1]+=x;
			}
			s.l=i+j+2;
			while(s.d[s.l]==0&&s.l>1) --s.l;
			return s;
		}
	i128 operator/(const int &t)
		{
			i128 ans;
			re int x=0,cnt=0;
			int ls[mxl];
			for(re int i=l;i>=1;--i)
				ls[++cnt]=(x*10+d[i])/t,x=(x*10+d[i])%t;
			if(cnt==1&&ls[1]==0){ans.l=1;return ans;}
			x=1;
			while(ls[x]==0) ++x;
			for(re int i=cnt;i>=x;--i) ans.d[cnt-i+1]=ls[i];
			ans.l=cnt-x+1;
			while(ans.d[ans.l]==0&&ans.l>1) --ans.l;
			return ans;
   		}
	bool operator>(const i128 &t)
		{
			if(l>t.l) return true;
			if(l<t.l) return false;
			for(re int i=l;i>=1;--i)
			{
				if(d[i]>t.d[i]) return true;
				else return false;
			}
		}
};
i128 fuck(int t)
{
	i128 ans;
	int cnt=0;
	while(t) ans.d[++cnt]=t%10,t/=10;
	ans.l=cnt;
	return ans;
}
struct node{int x,a,b;}s[10010];
bool cmp(const node &x1,const node &y1){if(x1.x<y1.x) return 1;return 0;}
int main()
{
    int n,i;
	i128 ans("1");
	n=read();
	s[0].a=read(),s[0].b=read();
    for(i=1;i<=n;i++)
	{
		s[i].a=read(),s[i].b=read();
        s[i].x=s[i].a*s[i].b;
    }
    sort(s+1,s+n+1,cmp);
	i128 mx("0");
	for(i=0;i<n;i++)
	{
		ans=ans*fuck(s[i].a);
		i128 t=ans/s[i+1].b;
		if(t>mx) mx=t;
	}
	mx.output();
    return 0;
}
