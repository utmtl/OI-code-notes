#include<cstdio>
#include<cstring>
#define re register
#define in inline
int n,m,l;
int trie[100000][26],endd[100000][1001],cnt=1;
in void insert(char *str,int num)
{
	int len=strlen(str),p=1;
	for(re int i=0;i<len;++i)
	{
		if(!trie[p][str[i]-'a']) trie[p][str[i]-'a']=++cnt;
		p=trie[p][str[i]-'a'];
	}
	++endd[p][num];
}
in void search(char *str)
{
	int len=strlen(str),p=1;
	for(re int i=0;i<len;++i)
	{
		p=trie[p][str[i]-'a'];
		if(!p) {printf("\n");return;}
	}
	for(re int i=1;i<=n;++i)
		if(endd[p][i]) printf("%d ",i);
	printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
	{
		scanf("%d",&l);
		for(re int j=1;j<=l;++j)
		{
			char str[25];
			scanf("%s",str);
			insert(str,i);
		}
	}
	scanf("%d",&m);
	for(re int i=1;i<=m;++i)
	{
		char str[25];
		scanf("%s",str);
		search(str);
	}
	return 0;
}
