#include<cstdio>
inline int read()//int快读
{
	int s=0,b=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=-1;
	}while(ch<='0' || ch>'9');
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return b*s;
}
int main()
{
	
	return 0;
}
