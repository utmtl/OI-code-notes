#include<cstdio>
#define intt long long
#define re register
#define in inline
int n;
char a[4][30];
int mmp[100],used[100],order[50];
in bool chk()
{
	int x=0;
	for(re int i=n-1;i>=0;--i)
	{
		if((mmp[a[1][i]]+mmp[a[2][i]]+x)%n!=mmp[a[3][i]]) return false;
		x=(mmp[a[1][i]]+mmp[a[2][i]]+x)/n;
	}
	if(x) return false;
	return true;
}
bool f=false;
void dfs(int step)
{
	if(f) return;//已经得到了答案, 直接return, 不然会浪费大量时间!!!
	if(mmp[a[1][0]]+mmp[a[2][0]]>n) return;
	for(re int i=n-1;i>=0;--i)
	{
		if(mmp[a[1][i]]==-1 || mmp[a[2][i]]==-1 || mmp[a[3][i]]==-1) continue;
		if(((mmp[a[1][i]]+mmp[a[2][i]]+1)%n!=mmp[a[3][i]]) &&((mmp[a[1][i]]+mmp[a[2][i]])%n!=mmp[a[3][i]])) return;
	}
	if(step==n)
	{
		if(chk())
		{
			for(re int i='A';i<='A'+n-1;++i)
				printf("%d ",mmp[i]);
		}
		f=true;
		return;
	}	
	for(re int i=n-1;i>=0;--i)
	{
		if(!used[i])
		{
			used[i]=1;
			mmp[order[step]]=i;
			dfs(step+1);
			used[i]=0;
			mmp[order[step]]=-1;
		}
	}
}
signed main()
{
	scanf("%d\n%s\n%s\n%s",&n,a[1],a[2],a[3]);
	//printf("%s\n%s\n%s",a[1],a[2],a[3]);
	int cnt=-1;
	for(re int i=n-1;i>=0;--i)
	{
		if(mmp[a[1][i]]==0) order[++cnt]=a[1][i],mmp[a[1][i]]=1;
		if(mmp[a[2][i]]==0) order[++cnt]=a[2][i],mmp[a[2][i]]=1;
		if(mmp[a[3][i]]==0) order[++cnt]=a[3][i],mmp[a[3][i]]=1;
	}//按字母枚举的先后顺序由字母从右往左的出现顺序决定
	for(re int i=1;i<100;++i) mmp[i]=-1;
	dfs(0);
	return 0;
}
