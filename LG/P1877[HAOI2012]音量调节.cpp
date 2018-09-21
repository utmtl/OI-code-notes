#include<iostream>
using namespace std;
int n,bl,ml,f[5000][5000],c[100];
//毒瘤数据，f1000,1000wa一个点
//01背包，f i，j表示第i首能否达到j音量，每首歌可选升或降
int main()
{
    cin>>n>>bl>>ml;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    f[0][bl]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=ml;j>=0;j--)
        {
            if(j+c[i]<=ml &&(f[i-1][j+c[i]]==1 || f[i][j]==1)) f[i][j]=1;
            if(j-c[i]>=0 &&(f[i-1][j-c[i]]==1 || f[i][j]==1)) f[i][j]=1;
        }
    }
    for(int i=ml;i>=0;i--)
    {
    	if(f[n][i]==1){
    		cout<<i;
    		return 0;
		}
	}
	cout<<"-1";
    return 0;
}
