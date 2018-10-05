/*
i
头尾相同的时候，最后肯定是剩下奇数个字母的，比如ababa
如果位数是奇数那么中间肯定进行了偶数次操作，否则就是奇数次

ii
头尾不同的话，最后剩下偶数个
如果位数为奇数就操作了奇数次，否则偶数次

-偶数次操作那么第一个人就无法操作就输，奇数次操作第二个人无法操作即输
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[100000];
    cin>>s;
    long long t=strlen(s);
    if(s[0]==s[strlen(s)-1]){
    	if(t%2==1) cout<<"Second"<<endl;
    	else cout<<"First"<<endl;
	}
	else{
		if(t%2==0) cout<<"Second"<<endl;
    	else cout<<"First"<<endl;
	}
    return 0;
}
