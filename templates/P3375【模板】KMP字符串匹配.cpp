/*下标从1开始
模式串s2: abcabc
文本串s1: abcabdababcabc
由于s2[4], s2[5]匹配成功, 而s2的前缀s2[1][2]=s2[4][5], 因此下次匹配模式串可以直接从3(c)开始与s1失配位置比较
j=next[j]:
模式串:    abcabc
文本串: abcabdababcabc
i=9, j=2(s2[1][2]匹配完毕)
kmp快就快在它不用一位一位的选定开头, 而是动态以最优的开头作比较
*/
#include<cstdio>
#include<cstring>
#define re register
#define in inline
#define int long long
char s1[10000010],s2[10000010];
int next[10000010],n,m;
signed main()
{
	scanf("%s\n%s",s1+1,s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
    //奇技淫巧: 让字符串从1开始
	for(re int i=2,j=0;i<=m;++i)
	{
		while(j && s2[i]!=s2[j+1]) j=next[j];//不能匹配就只能一个个跳回前一个j, 直至能与自己的一个前缀相同或只能回到串首从头匹配
		if(s2[j+1]==s2[i]) ++j;//能匹配就可以直接把j记录为next值
		next[i]=j;//next[x]记录x+1位失配时x的回跳位置
	}//求next[]:模式串自己匹配自己
	//next[]是针对模式串的, 记录了当模式串s2[x]失配时应跳转到哪一位, 即s2[1~next[x]]=s2[x-next[x]~x-1]
	//即s2的前缀(1~x)==以x-1结尾的等长中前缀, 这一部分一定相同, 不用再次逐一比较
	for(re int i=1,j=0;i<=n;++i)
	{//i为文本串位置, j为模式串已匹配部分的末尾位置
		while(j && s2[j+1]!=s1[i]) j=next[j];
        //j+1失配时j一直往前跳, 直至可以以j为起点继续匹配或跳到模式串串首
		if(s2[j+1]==s1[i]) ++j;//单字符匹配成功, ++j
		if(j==m){//全串匹配完成
			printf("%lld\n",i-m+1);
			j=next[j];//跳到下一个可匹配位置
		}
	}
	for(re int i=1;i<=m;++i)
		printf("%lld ",next[i]);
	return 0;
}
