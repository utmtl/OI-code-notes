#include<cstdio>
struct node{
	int a,b;
	node ()
	{
		a=1;
		b=2;
		printf("aaa\n");
	}
};
int main()
{
	node x;
	printf("%d\n%d\n",x.a,x.b);
	return 0;
}
