//f[i][j]:ѡ����ǰi�ֻ���һ��ѡ����j�軨�ķ������ܺ�
#include<iostream>
using namespace std;
int n,m,a[100000],f[9000][9000];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=a[i];k++)
			{
				f[i][j]+=(f[i-1][j-k]%1000007);
			}
		}
	}
	cout<<f[n][m]%1000007;
    return 0;
}
