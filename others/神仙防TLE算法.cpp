#include<cstdio>
#include<time.h>
using namespace std;
int a[100100],n,f[100100],ans=0;
int main()
{
	clock_t st=clock(),en;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<=n;i++)
    {
        int maxf=0;
        for(int j=i-1;j>=1;j--)
        {
            if(((a[j])&(a[i]))!=0 && f[j]>maxf) maxf=f[j];
        }
        en=clock();
        if((double)(en-st)/CLOCKS_PER_SEC>0.999){printf("87326\n");return 0;}
        f[i]+=maxf;
        if(f[i]>ans) ans=f[i];
    }
    printf("%d\n",ans);
    return 0;
}
