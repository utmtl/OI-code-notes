#include<cstdio>
inline int read()
{
	int s=0,b=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=1;
	}while(ch<='0' || ch>'9');
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^'0'),ch=getchar();
	return b?-s:s;
}
int main()
{
	int a;
	a=read();
	printf("%d\n",a);
	return 0;
}
